// Text histogram

using namespace std;

map<char, double> analyze_text(string_view text) {
	map<char, double> frequencies;
	for (char ch = 'a'; ch <= 'z'; ch++)
		frequencies[ch] = 0;
	for (auto ch : text) {
		if (isalpha(ch))
			frequencies[tolower(ch)]++;
	}
	auto total = accumulate(
		cbegin(frequencies), cend(frequencies),0ull,[](auto sum, auto const & kvp) {
			return sum + static_cast<unsigned long long>(kvp.second);});
	for_each(begin(frequencies), end(frequencies),[total](auto & kvp) {
		kvp.second = (100.0 * kvp.second) / total;
	});
	return frequencies;
}


int main() {
	auto result = analyze_text(R"(Lorem ipsum dolor sit amet, consectetur
		adipiscing elit, sed do eiusmod tempor incididunt ut labore et
		dolore magna aliqua.)");
	for (auto const & kvp : result) {
		cout << kvp.first << " : " << fixed << setw(5) << setfill(' ') << setprecision(2) << kvp.second << endl;
	}
}