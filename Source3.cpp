#include <iostream>
#include <cmath>

using namespace std;

string circleRotation(int x1, int y1, int r1, int x2, int y2, int r2) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	double dist = sqrt(dx * dx + dy * dy);
	if (dist > r1 + r2) {
		return "Окружности не пересекаются";
	}
	else if (dist == r1 + r2) {
		return "Окружности касаются в одной точке";
	}
	else if (dist == abs(r1 - r2)) {
		return "Одна окружность находится внутри другой и при этом они касаются в одной точке";
	}
	else if (dist < abs(r1 - r2)) {
		return "Одна окружность находится внутри другой";
	}
	else
		return "Окружности пересекаются в двух точках";
}

int main() {
	setlocale(LC_ALL, "Russian");
	int x1, y1, r1, x2, y2, r2;
	cout << "Введите координаты центра 1 окружности\n";
	cin >> x1 >> y1;
	cout << "Введите радиус 1 окружности\n";
	cin >> r1;
	cout << "Введите координаты центра 2 окружности\n";
	cin >> x2 >> y2;
	cout << "Введите радиус 2 окружности\n";
	cin >> r2;
	cout << circleRotation(x1, y1, r1, x2, y2, r2);
}