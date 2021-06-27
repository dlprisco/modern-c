// Prime factors of a number.

/*

  	  The prime factors of a positive integer are the prime numbers that divide that integer
    exactly. For instance, the prime factors of 8 are 2 x 2 x 2, and the prime factors of 42 are 2 x 3
    x 7. To determine the prime factors you should use the following algorithm:

		1. While n is divisible by 2, 2 is a prime factor and must be added to the list,
		while n becomes the result of n/2. After completing this step, n is an odd
		number.

		2. Iterate from 3 to the square root of n. While the current number, let’s call it i,
		divides n, i is a prime factor and must be added to the list, while n becomes the
		result of n/i. When i no longer divides n, increment i by 2 (to get the next odd
		number).

		3. When n is a prime number greater than 2, the steps above will not result
		in n becoming 1. Therefore, if at the end of step 2 n is still greater than 2, then n is
		a prime factor.

*/

using namespace std;

vector<unsigned long long> prime_factors(unsigned long long n) {
	vector<unsigned long long> factors;

	while (n % 2 == 0) {
		factors.push_back(2);
		n = n / 2;
	}

	for (unsigned long long i = 3; i <= std::sqrt(n); i += 2) {
		while (n%i == 0) {
			factors.push_back(i);
			n = n / i;
		}
	}

	if (n > 2) {
		factors.push_back(n);
	}

	return factors;
}

int main() {

	unsigned long long number = 0;
	cout << "number:";
	cin >> number;

	auto factors = prime_factors(number);
	copy(begin(factors), end(factors), ostream_iterator<unsigned long long>(cout, " "));

	narcissistics();

	return 0;
}

// Test value: 600,851,475,143. 