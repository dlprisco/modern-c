// Double buffer

/*

	The problem described here is a typical double buffering situation. Double buffering is the
 most common case of multiple buffering, which is a technique that allows a reader to see a
 complete version of the data and not a partially updated version produced by a writer. This
 is a common technique – especially in computer graphics – for avoiding flickering.

*/

using namespace std;

#include <algorithm>
#include <chrono>
#include <thread>
#include <iostream>
#include <vector>
#include <mutex>
#include <iterator>

//#include <random>

template <typename T>
class double_buffer {
	typedef T value_type;
	typedef T& reference;
	typedef T const & const_reference;
	typedef T* pointer;
public:
	explicit double_buffer(size_t const size) : rdbuf(size), wrbuf(size) {}
	size_t size() const noexcept { return rdbuf.size(); }
	void write(T const * const ptr, size_t const size) {
		unique_lock<mutex> lock(mt);
		auto length = min(size, wrbuf.size());
		copy(ptr, ptr + length, begin(wrbuf));
		wrbuf.swap(rdbuf);
	}
	template <class Output>
	void read(Output it) const {
		unique_lock<mutex> lock(mt);
		copy(cbegin(rdbuf), cend(rdbuf), it);
	}
	pointer data() const {
		unique_lock<mutex> lock(mt);
		return rdbuf.data();
	}
	reference operator[](size_t const pos) {
		unique_lock<mutex> lock(mt);
		return rdbuf[pos];
	}
	const_reference operator[](size_t const pos) const {
		unique_lock<mutex> lock(mt);
		return rdbuf[pos];
	}
	void swap(double_buffer other) {
		swap(rdbuf, other.rdbuf);
		swap(wrbuf, other.wrbuf);
	}
private:
	vector<T> rdbuf;
	vector<T> wrbuf;
	mutable mutex mt;
};

template <typename T>
void print_buffer(double_buffer<T> const & buf) {
	buf.read(ostream_iterator<T>(cout, " "));
	cout << endl;
}

int main() {
	double_buffer<int> buf(10);
	thread t([&buf]() {
		for (int i = 1; i < 1000; i += 10) {
			int data[] = { i, i + 1, i + 2, i + 3, i + 4, i + 5, i + 6,i + 7,i + 8,i + 9 }; 
			buf.write(data, 10);
			using namespace chrono_literals;
			this_thread::sleep_for(100ms);
		}
	});
	auto start = chrono::system_clock::now();

	do {
		print_buffer(buf);
		using namespace chrono_literals;
		this_thread::sleep_for(150ms);
	} while (chrono::duration_cast<chrono::seconds>(chrono::system_clock::now() - start).count() < 12);
	t.join();
}
