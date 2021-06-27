// Generating all the permutations of a string

/*

	You can solve this problem by taking advantage of some general-purpose algorithms from
 the standard library. The simplest of the two required versions is the non-recursive one, at
 least when you use next_permutation(). This function transforms the input range
 (that is required to be sorted) into the next permutation from the set of all possible
 permutations, ordered lexicographically with operator< or the specified comparison
 function object. If such a permutation exists then it returns true, otherwise, it transforms
 the range into the first permutation and returns false. Therefore, a non-recursive
 implementation based on next_permuation() looks like this:

*/

using namespace std;

void print_permutations(string str) {
	sort(begin(str), end(str));
	do {
		cout << str << endl;
	} while (next_permutation(begin(str), end(str)));
}

void next_permutation(string str, string perm) {
	if (str.empty()) cout << perm << endl;
	else {
		for (size_t i = 0; i < str.size(); ++i) {
			next_permutation(str.substr(1), perm + str[0]);
			rotate(begin(str), begin(str) + 1, end(str));
		}
	}
}

void print_permutations_recursive(string str) {
	next_permutation(str, "");
}

int main() {
	cout << "non-recursive version" << endl;
	print_permutations("main");
	cout << "recursive version" << endl;
	print_permutations_recursive("main");

	return 0;
}