// Greatest common divisor.

/*

   The greatest common divisor (gcd in short) of two or more non-zero integers, also known as
 the greatest common factor (gcf), highest common factor (hcf), greatest common measure
 (gcm), or highest common divisor, is the greatest positive integer that divides all of them.
 There are several ways the gcd could be computed; an efficient method is Euclid's
 algorithm. 

*/

using namespace std;
#include <numeric>

int main()
{
	unsigned int a = 0;
	unsigned int b = 0;

	cout << "For two integers, the algorithm is:\ngcd(a,0) = a\ngcd(a,b) = gcd(b, a mod b)" << endl;

	cout << "Please insert value a: ";
	cin >> a;

	cout << "Please insert value b: ";
	cin >> b;

	cout << "Greatest Common Divisor: " << gcd(a, b) << endl;

	return 0;
}