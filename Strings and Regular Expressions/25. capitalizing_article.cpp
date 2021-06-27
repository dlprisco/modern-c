// Capitalizing an article title

/*

	The function template capitalize(), implemented as follows, works with strings of any
 type of characters. It does not modify the input string but creates a new string. To do so, it
 uses an stringstream. It iterates through all the characters in the input string and
 sets a flag indicating a new word to true every time a space or punctuation is encountered.
 Input characters are transformed to uppercase when they represent the first character in a
 word and to lowercase otherwise:

*/

using namespace std;

template <class Elem>
using tstring = basic_string<Elem, char_traits<Elem>, allocator<Elem>>;

template <class Elem>
using tstringstream = basic_stringstream<Elem, char_traits<Elem>, allocator<Elem>>;

template <class Elem>
tstring<Elem> capitalize(tstring<Elem> const & text) {
	tstringstream<Elem> result;
	bool newWord = true;
	for (auto const ch : text) {
		newWord = newWord || ispunct(ch) || isspace(ch);
		if (isalpha(ch)) {
			if (newWord) {
				result << static_cast<Elem>(toupper(ch));
				newWord = false;
			}
			else
				result << static_cast<Elem>(tolower(ch));
		}
		else result << ch;
	}
	return result.str();
}

int main() {
	using namespace std::string_literals;
	assert("The C++ Challenger"s == capitalize("the c++ challenger"s));
	assert("This Is An Example, Should Work!"s ==
	capitalize("THIS IS an ExamplE, should wORk!"s));	

	return 0;
}
