// The most frequent element in a range

using namespace std;

template <typename T>
vector<pair<T, size_t>> find_most_frequent(vector<T> const & range) {
	map<T, size_t> counts;
	for (auto const & e : range) counts[e]++;
	auto maxelem = max_element(cbegin(counts), cend(counts),[](auto const & e1, auto const & e2) {
		return e1.second < e2.second;
	});

	vector<pair<T, size_t>> result;
	copy_if(begin(counts), end(counts),back_inserter(result),[maxelem](auto const & kvp) {return kvp.second == maxelem->second;});
	return result;
}

int main() {
	auto range = vector<int>{1,1,3,5,8,13,3,5,8,8,5};
	auto result = find_most_frequent(range);
	for (auto const & e : result) {
		cout << e.first << " : " << e.second << endl;
	}

	return 0;
}