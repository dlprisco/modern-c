// Sum of natural divislbe by 3 and 5.

/*

   The solution to this problem is to iterate through all numbers from 3 (1 and 2 are not
 divisible by 3 so it does not make sense to test them) up to the limit entered by the user. Use
 the modulo operation to check that the rest of the division of a number by 3 and 5 is 0.
 However, the trick to being able to sum up to a larger limit is to use long long and
 not int or long for the sum, which would result in an overflow before summing up to
 100,000:

*/

using namespace std;

int main()
{
	unsigned int limit = 0;
	cout << "Upper limit: ";
	cin >> limit;

	// Sum
	unsigned long long sum = 0

	return 0;
}