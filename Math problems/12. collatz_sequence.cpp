// Largest Collatz sequence.

/*
	The Collatz conjecture, also known as the Ulam conjecture, Kakutani's problem, the
  Thwaites conjecture, Hasse's algorithm, or the Syracuse problem, is an unproven conjecture
  that states that a sequence defined as explained in the following always reaches 1. The
  series is defined as follows: start with any positive integer n and obtain each new term from
  the previous one: if the previous term is even, the next term is half the previous term, or
  else it is 3 times the previous term plus 1.

*/

using namespace std;

pair<unsigned long long, long> longest_collatz(unsigned long long const limit) {
	long length = 0;
	unsigned long long number = 0;
	vector<int> cache(limit + 1, 0);

	for (unsigned long long i = 2; i <= limit; i++) {
		auto n = i;
		long steps = 0;
		
		while (n != 1 && n >= i) {
			if ((n % 2) == 0) n = n / 2;
			else n = n * 3 + 1;
			steps++;
		}

		cache[i] = steps + cache[n];
		if (cache[i] > length) { 
			length = cache[i];
			number = i;
		}
	}

	return make_pair(number, length);
}

int main() {

	unsigned long long number = 0;

	cout << "number";
	cin >> number;

	cout << longest_collatz(number) << endl;

	return 0;
}
