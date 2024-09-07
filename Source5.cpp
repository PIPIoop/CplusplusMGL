#include <iostream>

using namespace std;

struct Point {
	double x, y;
};


int orientation(Point p, Point q, Point r) {
	double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (val == 0) return 0; // �����������
	return (val > 0) ? 1 : 2; // 1 - �� �������, 2 - ������
}

bool doSegmentsIntersect(Point p1, Point q1, Point p2, Point q2) {
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	if (o1 != o2 && o3 != o4)
		return true;
	return false;
}

bool arePointsCollinear(Point p1, Point p2, Point p3) {
	return orientation(p1, p2, p3) == 0;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int x1, x2, y1, y2, x3, y3, x4, y4;
	cout << "������� ���������� ������ �����\n";
	cin >> x1 >> y1;
	cout << "������� ���������� ������ �����\n";
	cin >> x2 >> y2;
	cout << "������� ���������� ������� �����\n";
	cin >> x3 >> y3;
	cout << "������� ���������� ��������� �����\n";
	cin >> x4 >> y4;
	Point p1 = { x1, y1 }, q1 = { x2, y2 };
	Point p2 = { x3, y3 }, q2 = { x4, y4 };

	if (doSegmentsIntersect(p1, q1, p2, q2)) {
		std::cout << "\n������� ������������\n";
	}
	else {
		std::cout << "\n������� �� ������������\n";
	}

	if (arePointsCollinear(p1, p2, q1)) {
		std::cout << "\n����� 1,2,3 ����� �� ����� ������\n";
	}
	else {
		std::cout << "\n����� 1,2,3 �� ����� �� ����� ������\n";
	}


	
}