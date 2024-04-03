#include <iostream>

using namespace std;
const int N = 10;
int main()
{
	setlocale(LC_ALL, "Russian");
	double f[N], x[N], F, L, w = 1, a, M, val;
	int n, fact = 1;
	cout << "Введите степень интерполяционного многочлена: "; cin >> n;
	//cout << "\nВведите точку а для вычисления значения полинома: "; cin >> a;
	a = 3.1415926535;
	cout << "\nВведите массив узлов: " << endl;
	for (int i = 0; i <= n; i++)
	{
		cout << "x(" << i << ") = ";
		cin >> x[i];
	}
	//x[0] = 3; x[1] = 2.8; x[2] = 3.1; x[3] = 3.2;
	//a = 2.5;
	//x[0] = 1; x[1] = 2; x[2] = 3; x[3] = 4;
	cout << "\nЗначения функции в узлах:\n";
	for (int i = 0; i <= n; i++)
	{
		f[i] = sin(x[i]);
		cout << "f(x(" << i << ")) = " << f[i] << endl;
	}
	cout << endl;
	L = 0;
	for (int i = 0; i <= n; i++)
	{
		F = 1;
		for (int j = 0; j <= n; j++)
		{
			if (i != j)
				F *= (a - x[j]) / (x[i] - x[j]);
		}
		L += f[i] * F;
		//cout << F << endl;
	}
	float omega = 1;
	cout << "Введите константу М для оценки погрешности: "; cin >> M;
	for (int j = 0; j <= n; j++)
	{
		omega = omega * ((a - x[j]) / (j + 1));
	}
	val = M * omega;
	cout << "\nЗначение функции в точке а=" << a << ": " << sin(a);
	cout << "\n|f(a)-Ln(a)| = " << abs(sin(a) - L);
	cout << "\nL" << n << "(a) = " << L;
	cout << "\nОценка погрешности: " << val << endl;
	return 0;
}