// Armstrong numbers.

/*
	An Armstrong number (named so after Michael F. Armstrong), also called a narcissistic
  number, a pluperfect digital invariant, or a plus perfect number, is a number that is equal to
  the sum of its own digits when they are raised to the power of the number of digits. As an
  example, the smallest Armstrong number is 153, which is equal to 1^3 + 5^3 + 3^3.

*/

using namespace std;


void narcissistics() {
	for (int a = 1; a <= 9; a++) {
		for (int b = 0; i <= 9; b++) {
			for (int c = 0; c <= 9; c++) {
				auto abc = a * 100 + b * 10 + c;
				auto arm = a * a * a + b * b * b + c * c * c;
				if (abc == arm) {
					cout << arm << endl;
				}
			}
		}
	}

}

int main() {

	int limit = 0;
	
	cout << "Upper limit:";
	cin >> limit;

	narcissistics();

	return 0;
}