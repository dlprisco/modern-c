// String to binary conversion

/*

	The operation requested here is the opposite of the one implemented in the previous
 problem. This time, however, we could write a function and not a function template. The
 input is an std::string_view, which is a lightweight wrapper for a sequence of
 characters. The output is a vector of 8-bit unsigned integers. The
 following hexstr_to_bytes function transforms every two text characters into an
 unsigned char value ("A0" becomes 0xA0), puts them into an std::vector, and returns
 the vector:

*/

using namespace std;

unsigned char hexchar_to_int(char const ch) {
	if (ch >= '0' && ch <= '9') {
		return ch - '0';
	}
	if (ch >= 'A' && ch <= 'F') {
		return ch - 'A' + 10;
	}
	
	if (ch >= 'a' && ch <= 'f') {
		return ch - 'a' + 10;
	}
	throw std::invalid_argument("Invalid hexadecimal character");
}

vector<unsigned char> hexstr_to_bytes(std::string_view str) {
	vector<unsigned char> result;
	for (size_t i = 0; i < str.size(); i += 2) {
		result.push_back((hexchar_to_int(str[i]) << 4) | hexchar_to_int(str[i+1]));
	}
	return result;
}

 
//	  This function assumes the input string contains an even number of
//  hexadecimal digits. In cases where the input string contains an odd
//  number of hexadecimal digits, the last one is discarded (so that "BAD"
//  becomes {0xBA}). As a further exercise, modify the preceding function so
//  that, instead of discarding the last odd digit, it considers a leading zero so
//  that "BAD" becomes {0x0B, 0xAD}. Also, as yet another exercise, you
//  can write a version of the function that deserializes content that has the
//  hexadecimal digits separated by a delimiter, such as space (for example
//  "BA AD F0 0D").

int main() {
	vector<unsigned char> expected{ 0xBA, 0xAD, 0xF0, 0x0D, 0x42 };
	assert(hexstr_to_bytes("BAADF00D42") == expected);
	assert(hexstr_to_bytes("BaaDf00d42") == expected);
	return 0;
}