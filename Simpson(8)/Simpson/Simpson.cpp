#include "cmath"
#include <iostream>

using namespace std;


double f(double x) {
	return (sin(x));
}
int main() {
	setlocale(LC_ALL, "Russian");
	double a, b, eps;
	double s1, s;
	int n = 2; // ammount of start steps
	int step;
	cout << "Enter left limit a: ";
	cin >> a;
	cout << "\nEnter roght limit b: ";
	cin >> b;
	cout << "\nEnter accuracy eps: ";
	cin >> eps;
	double h = (b - a) / n;
	double k0 = f(a) + f(b), k1 = 0, k2 = 0;

	for (step = 1; step < n; step += 2) {
		k1 += f(a + step * h);
		k2 += f(a + (step + 1) * h);
	}
	s1 = h / 3 * (k0 + 4 * k1 + 2 * k2); //first approx for integral
	cout << "On first step: s = " << scientific << s1 << ", while n = " << n << endl;
	int i = 2;
	do {

		s = s1;
		n = 2 * n;
		k2 = k2 + k1;
		k1 = 0;
		h = (b - a) / n;
		for (step = 1; step < n; step += 2) {
			k1 += f(a + step * h);
			//k2 += f(a + (step + 1) * h);
		}
		s1 = h / 3 * (k0 + 4 * k1 + 2 * k2);
		cout << "On step " << i++ << ": s = " << scientific << s1 << ", while n = " << n << endl;
	} while (fabs(s1 - s) > eps);
	cout << "\nAnswer(integral): " << s1 << endl;

	system("pause");
}