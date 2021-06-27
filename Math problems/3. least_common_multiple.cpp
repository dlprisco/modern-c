// Least common multiple.

/*

     The least common multiple (lcm) of two or more non-zero integers, also known as the
   lowest common multiple, or smallest common multiple, is the smallest positive integer that
   is divisible by all of them. A possible way to compute the least common multiple is by
   reducing the problem to computing the greatest common divisor. 

*/

using namespace std;
#include <numeric>

int main()
{
	unsigned int a = 0;
	unsigned int b = 0;

	unsigned int first = 0;
	unsigned int last = 0;


	cout << "The following formula is used in this case:\nlcm(a, b) = abs(a, b) / gcd(a, b)" << endl;
	cout << "Please insert value a: ";
	cin >> a;

	cout << "Please insert value b: ";
	cin >> b;

	cout << "To compute the lcm for more than two integers values\n" << endl;
	cout << "Please insert value a: ";
	cin >> first;

	cout << "Please insert value b: ";
	cin >> last;

	cout << "Least common multiple: (Two values)" << lcm(a, b) << endl;
	cout << "Least common multiple: (More than two)" << accumulate(first, last, 1, lcm) << endl;

	return 0;
}