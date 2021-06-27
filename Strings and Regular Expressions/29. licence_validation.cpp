// License plate validation

/*

	The simplest way to solve this problem is by using regular expressions. The regular
  expression that meets the described format is "[A-Z]{3}-[A-Z]{2} \d{3,4}".
 
 	The first function only has to validate that an input string contains only text that matches
  this regular expression. For that, we can use regex_match(), as follows:

*/

using namespace std;

vector<string> extract_license_plate_numbers(string const & str) {
	regex rx(R"(([A-Z]{3}-[A-Z]{2} \d{3,4})*)");
	smatch match;
	vector<string> results;
	for(auto i = sregex_iterator(cbegin(str), cend(str), rx);i != sregex_iterator(); ++i) {
		if((*i)[1].matched)
			results.push_back(i->str());
	}

	return results;
}


int main() {
	vector<string> expected {"AAA-AA 123", "ABC-DE 1234", "XYZ-WW 0001"};
	string text("AAA-AA 123qwe-ty 1234 ABC-DE 123456..XYZ-WW 0001");
	assert(expected == extract_license_plate_numbers(text));

	return 0;
}