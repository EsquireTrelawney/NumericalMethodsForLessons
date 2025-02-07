#include <cmath>
#include <algorithm>
#include <fstream>
#include <iostream>


using namespace std;

double fun(double x)
{
	return (sin(x));
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int k1 = 0, k2 = 0;
	double eps, a, b, x, x_p, x_t, x_n;
	cout << "__________________________DICHOTOMY METHOD______________________________" << endl;;
	cout << "Enter accuracy(eps): ";
	cin >> eps;
	cout << endl;
	cout << "Enter left limit: ";
	cin >> a;
	cout << endl;
	cout << "Enter right limit: ";
	cin >> b;
	


	// dichotomy
	while (fabs(a - b) > eps)
	{
		x = (a + b) / 2;
		if (fun(a) * fun(x) < 0)
			b = x;
		else
			a = x;
		k1 = k1 + 1;
		cout << k1 << " iteration: " << fabs(x) << endl;
	}
	cout << endl << "Dichotomy solution: " << fabs(x) << endl;
	cout << "Number of iterations for calculations: " << k1 << endl;

	cout << "__________________________SECANT METHOD______________________________" << endl;;
	cout << "Enter first initial approximation: ";
	cin >> x_p;
	cout << endl;
	cout << "Enter second initial approximation: ";
	cin >> x_t;
	cout << endl;
	// secant method
	while (fabs(fun(x_t)) > eps)
	{
		x_n = x_t - ((x_t - x_p) / (fun(x_t) - fun(x_p)) * fun(x_t));
		x_t = x_n;
		k2 = k2 + 1;
		cout << k2 << " iteration: " << x_t << endl;
	}

	
	cout << "Secant method solution:  " << x_t << endl;
	cout << "Number of iterations for calculations:  " << k2 << endl;
}