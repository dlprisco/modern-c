// IPv4 data type

/*

	The problem requires writing a class to represent an IPv4 address. This is a 32-bit value,
 usually represented in decimal dotted format, such as 168.192.0.100; each part of it is an
 8-bit value, ranging from 0 to 255. For easy representation and handling, we can use four
 unsigned char to store the address value. Such a value could be constructed either from
 four unsigned char or from an unsigned long. In order to be able to read a value
 directly from the console (or any other input stream) and be able to write the value to the
 console (or any other output stream), we have to overload operator>> and operator<<.
 The following listing shows a minimal implementation that can meet the requested
 functionality:

*/
using namespace std;

class ipv4
{
	array<unsigned char, 4> data;

public:
	constexpr ipv4() : data{ {0} } {}
	constexpr ipv4(unsigned char const a, unsigned char const b,
				   unsigned char const c, unsigned char const d):
		data{{a, b, c, d}} {}

	explicit constexpr ipv4(unsigned long a) :
		data{ { static_cast<unsigned char>((a >> 24) & 0xFF),
				static_cast<unsigned char>((a >> 16) & 0xFF),
				static_cast<unsigned char>((a >> 8) & 0xFF),
				static_cast<unsigned char>(a & 0xFF) } } {}

	ipv4(ipv4 const & other) noexcept : data(other.data) {}
	ipv4 operator=(ipv4 const & other) noexcept {
		data = other.data;
		return *this;
	}

	string to_string() const {
		stringstream sstr;
		sstr << *this;
		return sstr.str();
	}

	constexpr unsigned long to_ulong() const noexcept {
		return (static_cast<unsigned long>(data[0]) << 24) |
			   (static_cast<unsigned long>(data[1]) << 16) |
			   (static_cast<unsigned long>(data[2]) << 8)  |
			   static_cast<unsigned long>(data[3]);
	}

	friend ostream& operator<<(ostream& os, const ipv4& a) {
		os << static_cast<int>(a.data[0]) << '.'
		   << static_cast<int>(a.data[1]) << '.'
		   << static_cast<int>(a.data[2]) << '.'
		   << static_cast<int>(a.data[3]);

		return os;
	}

	friend istream& operator>>(istream& is, ipv4& a) {
		char d1, d2, d3;
		int b1, b2, b3, b4;
		is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4;

		if (d1 == '.' && d2 == '.' && d3 == '.') {
			a = ipv4(b1, b2, b3, b4)
		}
		else {
			is.setstate(ios_base::failbit);
		}
		return is;
	}
};


// IPv4 class could be used as follows:
int int main(int argc, char const *argv[])
{
	ipv4 address(168, 192, 0, 1);
	cout << address << endl;

	ipv4 ip;
	
	cout << ip << endl;
	cin >> ip;

	if (!cin.fail()) {
		cout << ip << endl;
	}

	return 0;
}