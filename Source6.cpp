#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool sumZero(vector<int> n) {//1 ������
	while (n.size() > 1) {
		auto max = max_element(n.begin(), n.end());
		auto min = min_element(n.begin(), n.end());
		if (*max>=0 && *min>=0 || *max<0 && *min<0){
			return 0;
		}
		*max += *min;
		n.erase(min);
	}
	return n[0] == 0;
}

int arifmeticMean(int num1, int num2, int num3){//4 �������
	int answer = num1 / 3 + num2 / 3 + num3 / 3;
	int remains = (num1 % 3 + num2 % 3 + num3 % 3)%3;
	if (remains > 4)
		answer++;
	return answer;

}

bool checkPolygon(vector<int> sides) {//5 �������
	if (sides.size() < 3) {
		return 0;
	}
	int sum = 0;
	int maxSide = 0;
	for (int side : sides) {
		sum += side;
		if (side > maxSide)
			maxSide = side;
	}
	return sum - maxSide > maxSide;
}

struct Point {
	double x, y;
};

int orientation(Point p, Point q, Point r) {
	double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (val == 0)
		return 0; // �����������
	return (val > 0) ? 1 : 2; // 1 - �� �������, 2 - ������ �������
}


bool position(Point a, Point b, Point rayOrigin, double angle) {
	//����������� ����
	Point rayDirection;
	rayDirection.x = cos(angle);
	rayDirection.y = sin(angle);

	//�������
	Point segmentVector = { b.x - a.x, b.y - a.y };

	// �� ������ ���� �� ����� �������
	Point toSegmentStart = { a.x - rayOrigin.x, a.y - rayOrigin.y };
	Point toSegmentEnd = { b.x - rayOrigin.x, b.y - rayOrigin.y };

	//��������� ������������
	double crossStart = rayDirection.x * toSegmentStart.y - rayDirection.y * toSegmentStart.x;
	double crossEnd = rayDirection.x * toSegmentEnd.y - rayDirection.y * toSegmentEnd.x;

	//����� ���������� ���� => ��� ����� ��������� �� ���� ������� �� ����
	if (crossStart * crossEnd > 0) {
		return false;
	}

	// ���� �� ������ ������� �� ����?
	if (crossStart == 0 && (toSegmentStart.x * rayDirection.x >= 0 && toSegmentStart.y * rayDirection.y >= 0)) {
		return true; 
	}

	if (crossEnd == 0 && (toSegmentEnd.x * rayDirection.x >= 0 && toSegmentEnd.y * rayDirection.y >= 0)) {
		return true; 
	}

	return true; 
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "������� ���������� ��� ������ \n 1. ����� ����� ����� ����. \n \n 3.����������� ������� � ���� \n 4.������� �������������� \n 5.������� ��������������\n q-����� �����\n";
	string userInput;
	cin >> userInput;
	while (userInput != "q") {
		if (userInput == "1") {
			vector<int> num;
			int hs;
			cout << "������� ���������� �����, ��� ���������� ����� ������� ����� �����\n";
			while (cin >> hs) {
				num.push_back(hs);
			}
			if (sumZero(num)) {
				std::cout << "����� ����� ����� 0 \n" << std::endl;
			}
			else {
				std::cout << "����� ����� �� ����� 0 \n" << std::endl;
			}
		}
		else if (userInput == "4") {
			int num1, num2, num3;
			cout << "������� 3 ����� ��� ���������� �������� ��������������� \n";
			cin >> num1 >> num2 >> num3;
			cout << "������� �������������� ����� " << arifmeticMean(num1, num2, num3)<<'\n';
		}
		else if (userInput == "5") {
			int numSides;
			cout << "������� ���������� ������, ��� �������� �� ������������� �������������� \n";
			cin >> numSides;
			vector<int> sides(numSides);
			cout << "������� ����� ������\n";
			for (int i = 0; i < numSides; i++) {
				cin >> sides[i];
			}
			if (checkPolygon(sides)) {
				cout << "���� �����������, ��� �� ������ ������� �����, ������� ����� �������� ������� ������ ��������������\n" << endl;
			}
			else {
				cout << "����������� 0, ��� �� ������ ������� ����� ������ ��������������\n" << endl;
			}
		}
		else if (userInput == "3") {
			Point a, b, rayOrigin;
			double angle;
			cout << "������� ���������� ������ ������� (x1 y1): ";
			cin >> a.x >> a.y;

			cout << "������� ���������� ����� ������� (x2 y2): ";
			cin >> b.x >> b.y;

			cout << "������� ���������� ������ ���� (x0 y0): ";
			cin >> rayOrigin.x >> rayOrigin.y;

			cout << "������� ���� ����������� ���� � ��������: ";
			cin >> angle;

			if (position(a, b, rayOrigin, angle)) {
				cout << "��� ���������� �������." << endl;
			}
			else {
				cout << "��� �� ���������� �������." << endl;
			}

		}


		cout << "������� �������: \n";
		std::cin >> userInput;

	}


}