#include <iostream>
#include <cmath>

using namespace std;

string circleRotation(int x1, int y1, int r1, int x2, int y2, int r2) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	double dist = sqrt(dx * dx + dy * dy);
	if (dist > r1 + r2) {
		return "���������� �� ������������";
	}
	else if (dist == r1 + r2) {
		return "���������� �������� � ����� �����";
	}
	else if (dist == abs(r1 - r2)) {
		return "���� ���������� ��������� ������ ������ � ��� ���� ��� �������� � ����� �����";
	}
	else if (dist < abs(r1 - r2)) {
		return "���� ���������� ��������� ������ ������";
	}
	else
		return "���������� ������������ � ���� ������";
}

int main() {
	setlocale(LC_ALL, "Russian");
	int x1, y1, r1, x2, y2, r2;
	cout << "������� ���������� ������ 1 ����������\n";
	cin >> x1 >> y1;
	cout << "������� ������ 1 ����������\n";
	cin >> r1;
	cout << "������� ���������� ������ 2 ����������\n";
	cin >> x2 >> y2;
	cout << "������� ������ 2 ����������\n";
	cin >> r2;
	cout << circleRotation(x1, y1, r1, x2, y2, r2);
}