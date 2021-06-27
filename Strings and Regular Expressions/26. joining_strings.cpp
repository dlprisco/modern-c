// Joining strings together separated by a delimiter

/*

	Two overloads called join_strings() are listed in the following code. One takes a
 container of strings and a pointer to a sequence of characters representing a separator,
 while the other takes two random access iterators, representing the first and one past the
 last element of a range, and a separator. They both return a new string created by
 concatenating all the input strings, using an output string stream and the
 copy function. This general-purpose function copies all the elements in the specified
 range to an output range, represented by an output iterator. We are using here an
 ostream_iterator that uses operator<< to write the assigned value to the
 specified output stream each time the iterator is assigned a value:

*/

using namespace std;
template <typename Iter>
string join_strings(Iter begin, Iter end, char const * const separator) {
	ostringstream os;
	copy(begin, end-1, ostream_iterator<string>(os, separator));
	os << *(end-1);
	return os.str();
}

template <typename C>
string join_strings(C const & c, char const * const separator) {
	if (c.size() == 0) return string{};
	return join_strings(begin(c), end(c), separator);
}

int main() {

	using namespace string_literals;
	vector<string> v1{ "this","is","an","example" };
	vector<string> v2{ "example" };
	vector<string> v3{ };
	assert(join_strings(v1, " ") == "this is an example"s);
	assert(join_strings(v2, " ") == "example"s);
	assert(join_strings(v3, " ") == ""s);

	return 0;
}
