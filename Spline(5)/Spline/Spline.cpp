#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "RUS");

	system("color 80");
	double X[100], F[100], H[100], A[100], B[100], C[100], D[100], P[100], Q[100], Sol[100];
	double alpha0, alpha1, beta0, beta1, gamma0, gamma1, x0, res;
	int n;

	cout << "Ввод alpha0: ";
	cin >> alpha0;
	cout << "Ввод alpha1: ";
	cin >> alpha1;
	cout << "Ввод beta0: ";
	cin >> beta0;
	cout << "Ввод beta1: ";
	cin >> beta1;

	cout << "Ввод количества узлов: ";
	cin >> n;
	cout << "Ввод узлов и значений в них:";
	for (int i = 0; i <= n; i++)
	{
		cout << "X[" << i << "] = ";
		cin >> X[i];
		cout << "f[" << i << "] = ";
		cin >> F[i];
	}

	cout << "Ввод x0 для вычисления значений: ";
	cin >> x0;

	gamma0 = alpha0 * 3 * X[0] * X[0] + beta0 * 6 * X[0];
	gamma1 = alpha1 * 3 * X[n] * X[n] + beta1 * 6 * X[n];

	for (int i = 1; i <= n; i++)
		H[i] = X[i] - X[i - 1];

	for (int i = 1; i <= n - 1; i++)
		C[i] = H[i + 1] / 6;

	for (int i = 1; i <= n - 1; i++)
		B[i] = (H[i] + H[i + 1]) / 3;

	for (int i = 1; i <= n - 1; i++)
		A[i] = H[i] / 6;

	for (int i = 1; i <= n - 1; i++)
		D[i] = (F[i + 1] - F[i]) / H[i + 1] - (F[i] - F[i - 1]) / H[i];

	C[0] = -alpha0 * H[1] / 6;
	B[0] = -alpha0 * H[1] / 3 + beta0;

	B[n] = alpha1 * H[n] / 3 + beta1;
	A[n] = alpha1 * H[n] / 6;
	D[0] = gamma0 - alpha0 * (F[1] - F[0]) / H[1];
	D[n] = gamma1 - alpha1 * (F[n] - F[n - 1]) / H[n];

	C[n] = 0;
	A[0] = 0;

	P[0] = -C[0] / B[0];
	Q[0] = D[0] / B[0];

	for (int i = 1; i <= n - 1; i++)
	{
		P[i] = -C[i] / (B[i] + A[i] * P[i - 1]);
		Q[i] = (D[i] - A[i] * Q[i - 1]) / (B[i] + A[i] * P[i - 1]);
	}
	Sol[n] = (D[n] - A[n] * Q[n - 1]) / (B[n] + A[n] * P[n - 1]);
	for (int i = n - 1; i >= 0; i--)
		Sol[i] = P[i] * Sol[i + 1] + Q[i];

	cout << "gamma1 = " << gamma0 << endl;
	cout << "gamma1 = " << gamma1 << endl;

	cout << "Решение системы:" << endl;

	for (int i = 0; i <= n; i++)
		cout << "S[" << i << "] = " << Sol[i] << endl;

	int i = 0;
	while (x0 >= X[i])
		i++;

	cout << i << endl;

	res = Sol[i - 1] * (X[i] - x0) * (X[i] - x0) * (X[i] - x0) / (6 * H[i]) +
		Sol[i] * (x0 - X[i - 1]) * (x0 - X[i - 1]) * (x0 - X[i - 1]) / (6 * H[i]) +
		(F[i - 1] - Sol[i - 1] * H[i] * H[i] / 6) * (X[i] - x0) / H[i] +
		(F[i] - Sol[i] * H[i] * H[i] / 6) * (x0 - X[i - 1]) / H[i];

	cout << "Сплайн в точке  " << x0 << " = " << res << endl;

	system("pause");

}














































