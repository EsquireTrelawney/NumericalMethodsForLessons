
#include<math.h>
#include<stdio.h>
#include<iostream>
using namespace std;


double h0, eps;
double f(double x, double y)
{
	//return 5 * cos(5 * x) + sin(5 * x) * sin(5 * x) - y * y;
	//return cos(3 * x) + sin(3 * y);
	return exp(x) + y;
}

double Step(double x, double y, double h) {
	double phi0, phi1, phi2, phi3;

	phi0 = h * f(x, y);
	phi1 = h * f(x + h / 2, y + phi0 / 2);
	phi2 = h * f(x + h / 2, y + phi1 / 2);
	phi3 = h * f(x + h , y + phi2 );

	return y + (phi0 + 2 * phi1 + 2 * phi2 + phi3) / 6;
}

double jump(double x, double y, double *h) {

	double s1, s05, s2;
	*h = h0;
	s1 = Step(x, y, *h);
	s05 = Step(x, y, *h / 2);
	s2 = Step(x + *h / 2, s05, *h / 2);

	while (abs(s1 - s2) > eps) {
		*h  = *h/ 2;
		s1 = s05;
		s05 = Step(x, y, *h / 2);
		s2 = Step(x + *h / 2, s05, *h / 2);
	}

	return s2;
}
int main(){
	
	setlocale(LC_ALL, "russian");
	double x, X, x0, y0, y, h;

	cout << "f(x, y) = y + exp (x)" << endl;
	cout << "Enter x0 = "  ; // начало интервала
	cin >> x0;
	cout << "Enter X ="  ; // конец интервала
	cin >> X;
	cout << "Enter y0 = "  ; // начальное условие
	cin >> y0;
	cout << "Enter h0 = "  ; // шаг
	cin >> h0;
	cout << "Enter eps = " ; // точность
	cin >> eps;
	x = x0;
	y = y0;
	h = 0;
	cout.precision(10);
	while (x < X) {
		y0 = jump(x, y, &h);
		x += h;
		y = y0;
		cout << "h = " << h << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "Accuracy - " << y  - sin(5*x) << endl;
		if (X - x < h0)
			h0 = X - x;
	}
	//system("pause");
	return 0;

}


