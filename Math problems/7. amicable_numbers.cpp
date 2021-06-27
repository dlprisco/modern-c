// Amicable numbers.

/*

     Two numbers are said to be amicable if the sum of the proper divisors of one number is
  equal to that of the other number. The proper divisors of a number are the positive prime
  factors of the number other than the number itself. Amicable numbers should not be
  confused with friendly numbers. For instance, the number 220 has the proper divisors 1, 2, 4,
  5, 10, 11, 20, 22, 44, 55, and 110, whose sum is 284. The proper divisors of 284 are 1, 2, 4, 71,
  and 142; their sum is 220. Therefore, the numbers 220 and 284 are said to be amicable.

*/

using namespace std;
#include <cmath>

int sum_proper_divisors(int const number) {
	int result = 1;
	for (int i = 2; i <= sqrt(number); i++) {
		if (number%i == 0) {
			result += (i == (number/i)) ? i : (i + number / i);
		}
	}
	return result
}

void amicable(int const limit) {
	for (int number = 4; number <= limit; ++number) {
		auto sum1 = sum_proper_divisors(number);
		if (sum1 < limit) {
			auto sum2 = sum_proper_divisors(sum1);
			if (sum2 == number && number != sum1) {
				cout << number << ',' << sum1 << endl;
			}
		}
	}
}

int main() {

	int limit = 0;
	
	cout << "Upper limit:";
	cin >> limit;

	amicable(limit);

	return 0;
}