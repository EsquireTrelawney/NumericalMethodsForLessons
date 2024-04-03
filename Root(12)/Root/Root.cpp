#include <iostream>

using namespace std;

double Nth_root(double number, double power, double eps)
{
    double prev_y, next_y;

    next_y = number;
    do
    {
        prev_y = next_y;
        next_y = (prev_y * (power - 1) + number / pow(prev_y, power - 1)) / power;
        cout << "Approx: " << next_y << endl;
    } while (fabs(next_y - prev_y) > eps);
    return next_y;
}

int main() {
    system("color 80");
    int a, n;
    double eps = 0.00001;
    cout << "Input integers a, n. Programm'll calculate a^1/n: ";
    cin >> a >> n;
    cout << "Input accuracy eps: ";
    cin >> eps;
    double answer = Nth_root(a, n, eps);
    cout << endl << a << "^1/" << n << " = " << answer;

    return 0;
}