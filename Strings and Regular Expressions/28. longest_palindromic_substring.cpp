// Longest palindromic substring

/*
	The simplest solution to this problem is to try a brute-force approach, checking if each
 substring is a palindrome. However, this means we need to check C(N, 2) substrings (where
 N is the number of characters in the string), and the time complexity would be O(N^3). The
 complexity could be reduced to O(N^2) by storing results of sub problems. To do so we need
 a table of Boolean values, of size NxN, where the element at [i, j] indicates whether the
 substring from position i to j is a palindrome. We start by initializing all elements [i,i]
 with true (one-character palindromes) and all the elements [i,i+i] with true for all
 consecutive two identical characters (for two-character palindromes). We then go on to
 inspect substrings greater than two characters, setting the element at [i,j] to true if the
 element at [i+i,j-1] is true and the characters on the positions i and j in the string are
 also equal. Along the way, we retain the start position and length of the longest
 palindromic substring in order to extract it after finishing computing the table.

*/
using namespace std;

string longest_palindrome(string_view str) {
	size_t const len = str.size();
	size_t longestBegin = 0;
	size_t maxLen = 1;
	vector<bool> table(len * len, false);

	for (size_t i = 0; i < len; i++)
		table[i*len + i] = true;

	for (size_t i = 0; i < len - 1; i++) {
		if (str[i] == str[i + 1]) {
			table[i*len + i + 1] = true;
			if (maxLen < 2) {
				longestBegin = i;
				maxLen = 2;
			}
		}
	}

	for (size_t k = 3; k <= len; k++) {
		for (size_t i = 0; i < len - k + 1; i++) {
			size_t j = i + k - 1;
			if (str[i] == str[j] && table[(i + 1)*len + j - 1]) {
				table[i*len +j] = true;
				if (maxLen < k) {
					longestBegin = i;
					maxLen = k;
				}
			}
		}
	}
	return string(str.substr(longestBegin, maxLen));
}

int main() {
	using namespace string_literals;
	assert(longest_palindrome("sahararahnide") == "hararah");
	assert(longest_palindrome("level") == "level");
	assert(longest_palindrome("s") == "s");
	
	return 0;
}