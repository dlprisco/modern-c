// Transforming dates in strings

/*
	Text transformation can be performed with regular expressions using
  regex_replace(). A regular expression that can match dates with the specified
  formats is (\d{1,2})(\.|-|/)(\d{1,2})(\.|-|/)(\d{4}). This regex defines five
  capture groups; the 1st is for the day, the 2nd is for the separator (. or -), the 3rd is for the
  month, the 4th is again for the separator (. or -), and the 5th is for the year.

*/

using namespace std;

string transform_date(string_view text) {
	auto rx = regex{ R"((\d{1,2})(\.|-|/)(\d{1,2})(\.|-|/)(\d{4}))" };
	return regex_replace(text.data(), rx, R"($5-$3-$1)");
}

int main() {
	using namespace string_literals;
	assert(transform_date("today is 01.12.2017!"s) == "today is 2017-12-01!"s);

	return 0;
}