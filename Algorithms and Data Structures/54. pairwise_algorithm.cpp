// Pairwise algorithm
using namespace std;

template <typename Input, typename Output>
void pairwise(Input begin, Input end, Output result) {
	auto it = begin;
	while (it != end) {
		auto v1 = *it++; if (it == end) break;
		auto v2 = *it++;
		result++ = make_pair(v1, v2);
	}
}

template <typename T>
vector<pair<T, T>> pairwise(vector<T> const & range) {
	vector<pair<T, T>> result;
	pairwise(begin(range), end(range), back_inserter(result));
	return result;
}


int main() {
	vector<int> v{ 1, 1, 3, 5, 8, 13, 21 };
	auto result = pairwise(v);
	for (auto const & p : result) {
		cout << '{' << p.first << ',' << p.second << '}' << endl;
	}

	return 0;
}