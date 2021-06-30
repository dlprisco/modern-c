// Filtering a list of phone numbers

/*

	The solution to this problem is relatively simple: you have to iterate through all the phone
 numbers and copy to a separate container (such as an vector) the phone numbers
 that start with the country code. If the specified country code is, for instance, 44, then you
 must check for both 44 and +44. Filtering the input range in this manner is possible using
 the copy_if() function. A solution to this problem is shown here:

*/

#include <string>
#include <string_view>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool starts_with(string_view str, string_view prefix) {
	return str.find(prefix) == 0;
}

template <typename InputIt>
vector<string> filter_numbers(InputIt begin, InputIt end,string const & countryCode) {
	vector<string> result;
	copy_if(begin, end, back_inserter(result),
		[countryCode](auto const & number) {return starts_with(number, countryCode) || starts_with(number, "+" + countryCode);
	});
	return result;
}

vector<string> filter_numbers(vector<string> const & numbers,string const & countryCode) {
	return filter_numbers(cbegin(numbers), cend(numbers), countryCode);
}

int main() {
    
	vector<string> numbers{
		"+40744909080",
		"44 7520 112233",
		"+44 7555 123456",
		"40 7200 123456",
		"7555 123456"
	};
	auto result = filter_numbers(numbers, "44");
	
	for (auto const & number : result) {
		cout << number << endl;
	}
	
	return 0;
}
