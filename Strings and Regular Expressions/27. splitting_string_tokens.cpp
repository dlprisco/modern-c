// Splitting a string into tokens with a list of possible delimiters

/*
	Two different versions of a splitting function are listed as follows:


		The first one uses a single character as the delimiter. To split the input string it
	 uses a string stream initialized with the content of the input string,
	 using getline() to read chunks from it until the next delimiter or an endof-
	 line character is encountered.

	  	The second one uses a list of possible character delimiters, specified in
	 an string. It uses std:string::find_first_of() to locate the first
	 position of any of the delimiter characters, starting from a given position. It does
	 so in a loop until the entire input string is being processed. The extracted
	 substrings are added to the result vector:

*/

using namespace std;


template <class Elem>
using tstring = basic_string<Elem, char_traits<Elem>, allocator<Elem>>;

template <class Elem>
using tstringstream = basic_stringstream<Elem, char_traits<Elem>, allocator<Elem>>;

template<typename Elem>
inline vector<tstring<Elem>> split(tstring<Elem> text, Elem const delimiter) {
	auto sstr = tstringstream<Elem>{ text };
	auto tokens = vector<tstring<Elem>>{};
	auto token = tstring<Elem>{};
	while (getline(sstr, token, delimiter)) {
		if (!token.empty()) tokens.push_back(token);
	}
	return tokens;
}

template<typename Elem>
inline vector<tstring<Elem>> split(tstring<Elem> text, tstring<Elem> const & delimiters) {
	auto tokens = vector<tstring<Elem>>{};
	size_t pos, prev_pos = 0;
	while ((pos = text.find_first_of(delimiters, prev_pos)) != string::npos) {
		if (pos > prev_pos)
			tokens.push_back(text.substr(prev_pos, pos - prev_pos));
		prev_pos = pos + 1;
	}

	if (prev_pos < text.length())
		tokens.push_back(text.substr(prev_pos, string::npos));

	return tokens;
}

int main() {
	using namespace string_literals;
	vector<string> expected{"this", "is", "a", "sample"};
	assert(expected == split("this is a sample"s, ' '));
	assert(expected == split("this,is a.sample!!"s, ",.! "s));

	return 0;
}