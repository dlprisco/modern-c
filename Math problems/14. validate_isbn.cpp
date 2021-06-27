// Validating ISBNs.

/*

    The International Standard Book Number (ISBN) is a unique numeric identifier for books.
  Currently, a 13-digit format is used. However, for this problem, you are to validate the
  former format that used 10 digits. The last of the 10 digits is a checksum. This digit is
  chosen so that the sum of all the ten digits, each multiplied by its (integer) weight,
  descending from 10 to 1, is a multiple of 11.
 
    The validate_isbn_10 function, shown as follows, takes an ISBN as a string, and returns
  true if the length of the string is 10, all ten elements are digits, and the sum of all digits
  multiplied by their weight (or position) is a multiple of 11:

*/

using namespace std;

bool validate_isbn_10(string_view isbn) {
  auto valid = false;
  if (isbn.size() == 10 && count_if(begin(isbn), end(isbn), isdigit) == 10) {
    auto w = 10;
    auto sum = accumulate(begin(isbn), end(isbn), 0, [&w](int const total, char const c) {
      return total + w-- * (c - '0'); 
    });

    valid = !(sum % 11);
  }

  return valid;
}

int main() {

  string isbn = "";

  cout << "ISBN" << endl;
  cin >> isbn;

  cout << validate_isbn_10(isbn) <<  endl;

	return 0;
}
