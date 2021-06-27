// Select algorithm

using namespace std;

template <typename T, typename A, typename F, typename R = typename decay<typename result_of<typename decay<F>::type&(typename vector<T, A>::const_reference)>::type>::type> vector<R> select(vector<T, A> const & c, F&& f) {
	vector<R> v;
	transform(cbegin(c), cend(c),
	back_inserter(v),
	forward<F>(f));
	return v;
}

int main() {
	vector<book> books{
		{111, "Book 1", "book 1 author"},
		{222, "Book 2", "book 2 author"},
		{444, "Book 3", "book 3 author"}};

	auto titles = select(books, [](book const & b) {return b.title; });
	for (auto const & title : titles) {
		cout << title << endl;
	}

	return 0;
}