// Transforming a list of phone numbers

using namespace std;

bool starts_with(string_view str, string_view prefix) {
	return str.find(prefix) == 0;
}

void normalize_phone_numbers(vector<string>& numbers,string const & countryCode) {
	transform(cbegin(numbers), cend(numbers),begin(numbers),
		[countryCode](string const & number) { string result; 
			if (number.size() > 0) {
				if (number[0] == '0')
					result = "+" + countryCode + number.substr(1);
				else if (starts_with(number, countryCode))
					result = "+" + number;
				else if (starts_with(number, "+" + countryCode))
					result = number;
				else
					result = "+" + countryCode + number;
			}
			result.erase(remove_if(begin(result), end(result),
				[](const char ch) {return isspace(ch); }), end(result));
			return result;
		});
}

int main() {
	vector<string> numbers{
		"07555 123456",
		"07555123456",
		"+44 7555 123456",
		"44 7555 123456",
		"7555 123456"
	};
	normalize_phone_numbers(numbers, "44");
	for (auto const & number : numbers) {
		cout << number << endl;
	}
	return 0;
}
