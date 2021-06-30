// Zip algorithm
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template <typename Input1, typename Input2, typename Output>
void zip(Input1 begin1, Input1 end1, Input2 begin2, Input1 end2, Output result) {
	auto it1 = begin1;
	auto it2 = begin2;
	while (it1 != end1 && it2 != end2) {
		result++ = make_pair(*it1++, *it2++);
	}
}

template <typename T, typename U>
vector<pair<T, U>> zip(vector<T> const & range1, vector<U> const & range2) {
	vector<pair<T, U>> result;
	zip(begin(range1), end(range1),begin(range2), end(range2),back_inserter(result));
	return result;
}

int main() {
    cout<<"compiler";
	
	return 0;
}
