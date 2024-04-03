#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

void main()
{
	

	double x[10], f[10], Fi[10], m[10], a[10][10];
	int n, l, p, kCh, lZn, s;
	double Rn, RnCh, RnZn, aR, b, koef;

	cout << "Example(primer): (x*x*x - 2*x*x + 6)/(5*x*x + 1)" << endl;
	cout << "kCH = ";
	cin >> p;
	cout << "lZn = ";
	cin >> l;

	n = l + p;
	kCh = 3;
	lZn = 2;

	cout << "n = " << n << endl;
	cout << "Enter nodes(vvedite uzly): " << endl;
	for (int i = n; i < 10; i++)
		x[i] = 0;
	for (int i = 0; i <= n; i++)
	{
		cout << "x[" << i << "] = ";
		cin >> x[i];
	}

	aR = 8;
	a[n + 2][n + 2] = 1;

	cout << "Nodes value(znacheniya v uzlah) : " << endl;

	for (int i = 1; i <= n + 1; i++)
	{
		f[i] = (x[i] * x[i] * x[i] - 2 * x[i] * x[i] + 6) / (5 * x[i] * x[i] + 1);
		cout << "f[" << i << "] = " << f[i] << endl;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 1; i <= n + 1; i++)
	{
		for (int j = 1; j <= kCh + 1; j++)
		{
			a[i][j] = 1;
			for (int k = 1; k <= kCh - j + 1; k++)
				a[i][j] *= x[i];
		}
		for (int j = kCh + 2; j <= n + 1; j++)
		{
			a[i][j] = -f[i];
			for (int k = 1; k <= j - lZn - 1; k++)
				a[i][j] *= x[i];
		}
	}
	for (int i = 1; i <= n + 1; i++)
		a[i][n + 2] = f[i];

	cout << "Matrix:" << endl;
	for (int i = 1; i <= n + 1; i++)
	{
		for (int j = 1; j <= n + 2; j++)
			cout << a[i][j] << "	";
		cout << endl;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for (int j = 1; j <= n + 1; j++)
	{
		s = j;
		for (int i = j; i <= n; i++)
		{
			if (abs(a[i][j]) < abs(a[i + 1][j]))
				s = i + 1;
		}
		for (int k = 1; k <= n + 2; k++)
		{
			m[k] = a[j][k];
			a[j][k] = a[s][k];
			a[s][k] = m[k];
		}
		if (a[j][j] != exp(log(10) * (-15)))
			koef = a[j][j];
		else
		{
			cout << "The matrix is ​​degenerate. " << endl;
			system("pause");
			exit;
		}
		for (int k = 1; k <= n + 2; k++)
			a[j][k] = a[j][k] / koef;
		for (int k = 1; k <= n + 1; k++)
		{
			if (k != j)
			{
				koef = a[k][j];
				for (int i = 1; i <= n + 2; i++)
					a[k][i] -= a[j][i] * koef;
			}
		}
	}

	cout << "Matrix after transformations:" << endl;
	for (int i = 1; i <= n + 1; i++)
	{
		for (int j = 1; j <= n + 2; j++)
			cout << a[i][j] << "	";
		cout << endl;
	}

	cout << "Numerator ratios(koefficienty chislitelya): " << endl;
	for (int i = 1; i <= kCh + 1; i++)
		cout << "a[" << abs(kCh + 1 - i) << "] = " << a[i][n + 2] << endl;
	cout << "Denominator ratios:(koefficienty znamenatelya): " << endl;
	for (int i = kCh + 2; i <= n + 2; i++)
		cout << "b[" << n + 2 - i << "] = " << a[i][n + 2] << endl;
	system("pause");

}