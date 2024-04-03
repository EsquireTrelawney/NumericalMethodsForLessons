#include <iostream>
using namespace std;

double** mult(double** x, int n, double** y)
{
	double temp = 0;
	double** mt;
	mt = new double* [n];
	for (int i = 0; i < n; i++) {
		mt[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			mt[i][j] = 0;
			for (int k = 0; k < n; k++)
				mt[i][j] += x[i][k] * y[k][j];
		}
	}
	return mt;
}
double** shape(double** x, int n, double** y)
{
	double** mt;
	mt = new double* [n];
	for (int i = 0; i < n; i++)
		mt[i] = new double[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mt[i][j] = x[i][j] - y[i][j];
		}
	}
	return mt;
}
double** Gauss(double** A, int n)
{
	setlocale(LC_CTYPE, "Russian");
	double max, temp;
	int imax;
	for (int k = 0; k < n; k++)
	{
		imax = k;
		max = A[k][k];
		for (int i = k; i < n; i++)
			if (abs(A[i][k]) > abs(max))
			{
				max = A[i][k];
				imax = i;
			}
		if (max == 0)
		{
			cout << "Матрица вырождена";
			break;
		}
		for (int i = k; i < 2 * n; i++)
			swap(A[k][i], A[imax][i]);

		for (int i = k + 1; i < n; i++)
		{
			temp = A[i][k] / A[k][k];
			for (int j = k; j < 2 * n; j++)
				A[i][j] -= A[k][j] * temp;
		}

		for (int i = 0; i < k; i++)
		{
			temp = A[i][k] / A[k][k];
			for (int j = k; j < 2 * n; j++)
				A[i][j] -= A[k][j] * temp;
		}
	}
	for (int i = 0; i < n; i++)
	{
		temp = A[i][i];
		for (int j = i; j < 2 * n; j++)
			A[i][j] /= temp;
	}
	return A;
}
void view_full(double** a, int n)
{
	cout.precision(3);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "\t";
		printf("|");
		for (int j = n; j < 2 * n; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}
void view(double** a, int n)
{
	cout.precision(3);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << "\t";
		printf("|");
		for (int j = n; j < 2 * n; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
}
double max(int n, double** x)
{
	double max = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (fabs(x[i][j]) > max)
				max = x[i][j];
	return max;
}к 
int main()
{
	setlocale(LC_CTYPE, "Russian");
	system("color 80");
	int n = 5;
	int k = n;
	double** x, ** e, ** xk, ** a, ** e2;
	x = new double* [n];
	e = new double* [n];
	xk = new double* [n];
	a = new double* [n];
	e2 = new double* [n];
	for (int i = 0; i < n; i++)
	{
		x[i] = new double[2 * n];
		e[i] = new double[n];
		xk[i] = new double[n];
		a[i] = new double[n];
		e2[i] = new double[n];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			x[i][j] = rand() % 15;
			a[i][j] = x[i][j];
		}
	for (int i = 0; i < n; i++)
		for (int j = n; j < 2 * n; j++)
			x[i][j] = 0;
	for (int i = 0; i < n; i++)
	{
		x[i][k] = 1;
		k++;
	}
	view_full(x, n);
	Gauss(x, n);
	cout << endl;
	cout.precision(10);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			xk[i][j] = x[i][j + n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << xk[i][j] << "\t";
		cout << endl;
	}
	 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
			{
				e[i][j] = 0;
				e2[i][j] = 0;
			}
			else {
				e[i][j] = 1;
				e2[i][j] = 2;
			}
	cout << endl;

	cout.precision(15);
	/*for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			xk[i][j] = x[i][j+n];*/
	cout << "\nПосле Гаусса обратная матрица имеет следующую погрешность : " << max(n, shape(e, n, mult(a, n, xk)));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			xk[i][j] *= 0.9;
	cout << endl;

	cout << "\nИспорченная обратная матрица имеет следующую погрешность : " << max(n, shape(e, n, mult(a, n, xk)));
	for (int k = 0; k < n; k++)
	{
		xk = mult(xk, n, shape(e2, n, mult(a, n, xk)));
		cout << "\n" << k + 1 << " -ое приближение: " << max(n, shape(e, n, mult(a, n, xk)));
	}
	cout << endl;
	system("pause");
}


