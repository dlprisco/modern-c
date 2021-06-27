// System handle wrapper

/*
    System handles are a form of reference to system resources. Because all operating systems
 were at least initially written in C, creating and releasing the handles is done through
 dedicated system functions. This increases the risk of leaking resources because of
 erroneous disposal, such as in the case of an exception. In the following snippet, specific to
 Windows, you can see a function where a file is opened, read from, and eventually closed.
 However, this has a couple of problems: in one case, the developer forgot to close the
 handle before leaving the function; in another case, a function that throws is called before
 the handle is properly closed, without the exception being caught. However, since the
 function throws, that cleanup code never executes:

*/
using namespace std;

void bad_handle_example() {
    bool condition1 = false;
    bool condition2 = true;
    HANDLE handle = CreateFile(L"sample.txt", GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

    if (handle == INVALID_HANDLE_VALUE) {
        return;
    }

    if (condition1) {
        CloseHandle(handle);
        return;
    }
    vector<char> buffer(1024);
    unsigned long bytesRead = 0;
    ReadFile(handle, buffer.data(), buffer.size(), &bytesRead, nullptr);

    if (condition2) {
        // oops, forgot to close handle
        return;
    }

    // throws exception; the next line will not execute
    function_that_throws();
    CloseHandle(handle);
}

template <typename Traits>
class unique_handle {
    using pointer = typename Traits::pointer;
    pointer m_value;

public:
    unique_handle(unique_handle const &) = delete;
    unique_handle& operator=(unique_handle const &) = delete;
    explicit unique_handle(pointer value = Traits::invalid()) noexcept:m_value { 
        value
    }

    {} unique_handle(unique_handle && other) noexcept : m_value { 
        other.release() 
    }

    {} unique_handle& operator=(unique_handle && other) noexcept {
        if (this != &other) {
            reset(other.release());
        }
    return *this;
    }

    ~unique_handle() noexcept {
        Traits::close(m_value);
    }

    explicit operator bool() const noexcept {
        return m_value != Traits::invalid();
    }

    pointer get() const noexcept {
        return m_value; 
    }
    
    pointer release() noexcept {
        auto value = m_value;
        m_value = Traits::invalid();
        return value;
    }
    bool reset(pointer value = Traits::invalid()) noexcept {
        if (m_value != value) {
            Traits::close(m_value);
            m_value = value;
        }
    return static_cast<bool>(*this);
    }

    void swap(unique_handle<Traits> & other) noexcept {
        swap(m_value, other.m_value);
    }
};

template <typename Traits>
void swap(unique_handle<Traits> & left, unique_handle<Traits> & right) noexcept {
    left.swap(right);
}

template <typename Traits>
bool operator==(unique_handle<Traits> const & left, unique_handle<Traits> const & right) noexcept {
    return left.get() == right.get();
}

template <typename Traits>
bool operator!=(unique_handle<Traits> const & left, unique_handle<Traits> const & right) noexcept {
    return left.get() != right.get();
}

struct null_handle_traits {
    using pointer = HANDLE;
    static pointer invalid() noexcept {
        return nullptr; 
    }
    
    static void close(pointer value) noexcept {
        CloseHandle(value);
    }
};

struct invalid_handle_traits {
    using pointer = HANDLE;
    static pointer invalid() noexcept { 
        return INVALID_HANDLE_VALUE; 
    }
    
    static void close(pointer value) noexcept {
        CloseHandle(value);
    }
};

using null_handle = unique_handle<null_handle_traits>;
using invalid_handle = unique_handle<invalid_handle_traits>;

void good_handle_example() {
    bool condition1 = false;
    bool condition2 = true;
    invalid_handle handle{CreateFile(L"sample.txt", GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr) };

    if (!handle) {
        return;
    }

    if (condition1){
        return;
    }

    vector<char> buffer(1024);
    unsigned long bytesRead = 0;
    ReadFile(handle.get(), buffer.data(), buffer.size(), &bytesRead, nullptr);

    if (condition2) {
        return;
    }
    function_that_throws();
}
