// Gray code.

/*

	Gray code, also known as reflected binary code or simply reflected binary, is a form of
  binary encoding where two consecutive numbers differ by only one bit. To perform a
  binary reflected Gray code encoding, we need to use the following formula:
 
  if b[i-1] = 1 then g[i] = not b[i]
  else g[i] = b[i]

  This is equivalent to the following:

  g = b xor (b logically right shifted 1 time)

  For decoding a binary reflected Gray code, the following formula should be used:

  b[0] = g[0]
  b[i] = g[i] xor b[i-1]

  These can be written in C++ as follows, for 32-bit unsigned integers

*/

using namespace std;

unsigned int gray_encode(unsigned int const num) {
	return num ^ (num >> 1);
}

unsigned int gray_decode(unsigned int gray) {
	for (unsigned int bit = 1U << 31; bit > 1; bit >>= 1) {
		if (gray & bit) gray ^= bit >> 1;
	}

	return gray;
}

string to_binary(unsigned int value, int const digits) {
	return bitset<32>(value).to_string().substr(32-digits, digits);
}

int main() {

	cout << "Number\tBinary\tGray\tDecoded\n";
	cout << "------\t------\t----\t-------\n";

	for (unsigned int n = 0; n < 32; ++n) {
		auto encg = gray_encode(n);
		auto decg = gray_decode(encg);

		cout << n << "\t" << to_binary(n, 5) << "\t"
			 << to_binary(encg, 5) << "\t" << decg << "\n";
	}


	return 0;
}
