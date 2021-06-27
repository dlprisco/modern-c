// Binary to string conversion

/*

	In order to write a general-purpose function that can handle various sorts of ranges, such as
 an std::array, std::vector, a C-like array, or others, we should write a function
 template. In the following, there are two overloads; one that takes a container as an
 argument and a flag indicating the casing style, and one that takes a pair of iterators (to
 mark the first and then one past the end element of the range) and the flag to indicate
 casing. The content of the range is written to an std::ostringstream object, with the
 appropriate I/O manipulators, such as width, filling character, or case flag:

*/

using namespace std;

template <typename Iter>
string bytes_to_hexstr(Iter begin, Iter end, bool const uppercase = false) {
	ostringstream oss;

	if (uppercase) {
		oss.setf(ios_base::uppercase);
	}

	for (; begin != end; ++begin) {
		oss << hex << setw(2) << setfill('0') << static_cast<int>(*begin);
	}

	return oss.str();
}

template <typename C>
string bytes_to_hexstr(C const & c, bool const uppercase = false) {
	return bytes_to_hexstr(std::cbegin(c), std::cend(c), uppercase);
}

int main() {

	vector<unsigned char> v{ 0xBA, 0xAD, 0xF0, 0x0D };
	array<unsigned char, 6> a{ {1,2,3,4,5,6} };
	unsigned char buf[5] = {0x11, 0x22, 0x33, 0x44, 0x55};
	
	assert(bytes_to_hexstr(v, true) == "BAADF00D");
	assert(bytes_to_hexstr(a, true) == "010203040506");
	assert(bytes_to_hexstr(buf, true) == "1122334455");
	assert(bytes_to_hexstr(v) == "baadf00d");
	assert(bytes_to_hexstr(a) == "010203040506");
	assert(bytes_to_hexstr(buf) == "1122334455");

	return 0;
}