// Sort algorithm
#include <algorithm>
#include <array>
#include <stack>
#include <vector>
using namespace std;

template <class RandomIt>
RandomIt partition(RandomIt first, RandomIt last) {
	auto pivot = *first;
	auto i = first + 1;
	auto j = last - 1;
	while (i <= j) {
		while (i <= j && *i <= pivot) i++;
		while (i <= j && *j > pivot) j--;
		if (i < j) iter_swap(i, j);
	}
	iter_swap(i - 1, first);
	return i - 1;
}

template <class RandomIt>
void quicksort(RandomIt first, RandomIt last) {
	if (first < last) {
		auto p = partition(first, last);
		quicksort(first, p);
		quicksort(p + 1, last);
	}
}

template <class RandomIt, class Compare>
RandomIt partitionc(RandomIt first, RandomIt last, Compare comp) {
	auto pivot = *first;
	auto i = first + 1;
	auto j = last - 1;
	while (i <= j) {
		while (i <= j && comp(*i, pivot)) i++;
		while (i <= j && !comp(*j, pivot)) j--;
		if (i < j) iter_swap(i, j);
	}
	iter_swap(i - 1, first);
	return i - 1;
}

template <class RandomIt, class Compare>
void quicksort(RandomIt first, RandomIt last, Compare comp) {
	if (first < last) {
		auto p = partitionc(first, last, comp);
		quicksort(first, p, comp);
		quicksort(p + 1, last, comp);
	}
}

template <class RandomIt>
void quicksorti(RandomIt first, RandomIt last) {
	stack<pair<RandomIt, RandomIt>> st;
	st.push(make_pair(first, last));
	while (!st.empty()) {
		auto iters = st.top();
		st.pop();
		if (iters.second - iters.first < 2) continue;
	    auto p = partition(iters.first, iters.second);
		st.push(make_pair(iters.first, p));
		st.push(make_pair(p+1, iters.second));
	}
}

int main() {
	vector<int> v{ 1,5,3,8,6,2,9,7,4 };
	quicksort(begin(v), end(v));

	array<int, 9> a{ 1,2,3,4,5,6,7,8,9 };
	quicksort(begin(a), end(a));

	int a1[]{ 9,8,7,6,5,4,3,2,1 };
	quicksort(begin(a1), end(a1));

	vector<int> v1{ 1,5,3,8,6,2,9,7,4 };
	quicksort(begin(v1), end(v1), greater<>());


	vector<int> v2{ 1,5,3,8,6,2,9,7,4 };
	quicksorti(begin(v2), end(v2));

	return 0;
}
