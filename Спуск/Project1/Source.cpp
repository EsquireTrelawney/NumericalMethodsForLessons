#include <cstdlib>
#include <iostream>

using namespace std;

double Sproduct(double* x, double* y, int n)
{
	double S = 0;
	for (int i = 1; i <= n; i++)
		S += x[i] * y[i];
	return S;
}

void Dif(double* a, double* b, int n)
{
	for (int i = 1; i <= n; i++)
		a[i] -= b[i];
}

void GOM(double* b, double* bt, int n, double t)
{
	for (int i = 1; i <= n; i++)
		bt[i] = b[i] * t;

}

void Multiplic(double A[100][100], double* b, double* ab, int n)
{
	for (int i = 1; i <= n; i++)
	{
		ab[i] = 0;
		for (int j = 1; j <= n; j++)
			ab[i] += A[i][j] * b[j];
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	system("color 80");
	double  ab[100], b[100], f[100], bt[100], w[100], y[100], wt[100], x[100], yt[100];
	double A[100][100];
	double T = 0, C = 0, S = 0, e = 0, k = 0;
	int n, count;

	cout << "����������� ������� ������: ";
	cin >> n;
	cout << "�������� ��� �����������: ";
	cin >> e;

	for (int i = 1; i <= n; i++)
	{
		f[i] = 0;
		wt[i] = 0;
		yt[i] = 0;
		x[i] = 0;
		y[i] = 0;
		b[i] = 0;
		w[i] = 0;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			A[i][j] = 1.0 / (i + j - 1.0);
			f[i] += A[i][j];
		}

	Multiplic(A, b, w, n);
	Dif(w, f, n);
	Multiplic(A, w, y, n);

	C = Sproduct(y, w, n);
	count = 0;

	while (C >= e * e)
	{
		T = Sproduct(w, w, n) / C;
		GOM(w, wt, n, T);
		Dif(x, wt, n);
		GOM(y, yt, n, T);
		Dif(w, yt, n);

		Multiplic(A, w, y, n);
		C = Sproduct(y, w, n);

		count++;
	}

	cout << "������� ��������: " << C << endl;
	cout << "���������� ��������: " << count << endl;
	cout << "�������: " << endl;
	for (int i = 1; i <= n; i++)
		cout << "x[" << i << "] = " << x[i] << endl;

	system("pause");
}