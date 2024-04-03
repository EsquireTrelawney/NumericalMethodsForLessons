#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUS");
	int n = 4;
	cout << "Введите степень многочлена: 3" << endl;

	float* massForX = new float[n];
	float* massForFX = new float[n];
	float X0, Lx, t;

	cout << "Введите массив узлов:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "x" << i + 1 << " = ";
		cin >> massForX[i];
		massForFX[i] = sin(massForX[i]);
		cout << "F(" << massForX[i] << ") = " << massForFX[i] << endl;
		//cin >> FXarray[i];
	}


	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			massForFX[j] = (massForFX[j] - massForFX[j - 1]) / (massForX[j] - massForX[j - i - 1]);


	cout << endl << "Точка для вычисления значения :" << endl << "a = " << "3.1415926535" << endl;
	X0 = 3.1415926535;
	//cin >> X0;

	Lx = massForFX[0];
	t = 1;
	for (int i = 0; i < n - 1; i++)
	{
		t = t * (X0 - massForX[i]);
		Lx = Lx + massForFX[i + 1] * t;
		cout << "Lx[" << i + 1 << "] = " << Lx << endl;
	}
	system("pause");
}