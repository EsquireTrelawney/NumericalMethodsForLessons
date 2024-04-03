#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

void main()
{
	system("color 80");
	setlocale(LC_ALL, "RUS");
	double ax, bx, ay, by, x, y, z, sum = 0;
	int n, m, s = 0;
	srand(time(0));

	cout << "Необходимое кол-во точек: ";
	cin >> n;
	cout << "Необходимое кол-во попыток для вычисления интеграла: ";
	cin >> m;
	cout << "Отрезок для интегрирования по x: " << endl << "a = ";
	cin >> ax;
	cout << "b = ";
	cin >> bx;
	cout << "Отрезок для интегрирования по y: " << endl << "a = ";
	cin >> ay;
	cout << "b = ";
	cin >> by;
	cout << "Значение интеграла: 0.405285" << endl;
	cout << "Значение интеграла через математическое ожидание: " << endl;

	for (int j = 1; j <= m; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			x = ax + (bx - ax) * (rand() % 100) / (100 * 1.0);
			y = ay + (by - ay) * (rand() % 100) / (100 * 1.0);
			sum += sin(acos(-1) * x) * cos((acos(-1) * y) / 2);
		}
		sum /= n;
		cout << j << ": " << sum << endl;
	}

	cout << "Значение через количество удачных испытаний: " << endl;
	for (int j = 1; j <= m; j++)
	{
		s = 0;
		for (int i = 1; i <= n; i++)
		{
			x = ax + (bx - ax) * (rand() % 100) / (100 * 1.0);
			y = ay + (by - ay) * (rand() % 100) / (100 * 1.0);
			z = (rand() % 100) / (100 * 1.0);
			if (sin(acos(-1) * x) * cos((acos(-1) * y) / 2) >= z)
				s++;
		}
		sum = (double)s / n;
		cout << j << ": " << sum << endl;
	}
	system("pause");
}