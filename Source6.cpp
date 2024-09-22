#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool sumZero(vector<int> n) {//1 Задача
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

int arifmeticMean(int num1, int num2, int num3){//4 задание
	int answer = num1 / 3 + num2 / 3 + num3 / 3;
	int remains = (num1 % 3 + num2 % 3 + num3 % 3)%3;
	if (remains > 4)
		answer++;
	return answer;

}

bool checkPolygon(vector<int> sides) {//5 задание
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
		return 0; // Коллинеарны
	return (val > 0) ? 1 : 2; // 1 - по часовой, 2 - против часовой
}


bool position(Point a, Point b, Point rayOrigin, double angle) {
	//направление луча
	Point rayDirection;
	rayDirection.x = cos(angle);
	rayDirection.y = sin(angle);

	//отрезок
	Point segmentVector = { b.x - a.x, b.y - a.y };

	// от начала луча до конца отрезка
	Point toSegmentStart = { a.x - rayOrigin.x, a.y - rayOrigin.y };
	Point toSegmentEnd = { b.x - rayOrigin.x, b.y - rayOrigin.y };

	//векторное произведение
	double crossStart = rayDirection.x * toSegmentStart.y - rayDirection.y * toSegmentStart.x;
	double crossEnd = rayDirection.x * toSegmentEnd.y - rayDirection.y * toSegmentEnd.x;

	//имеют одинаковый знак => обе точки находятся по одну сторону от луча
	if (crossStart * crossEnd > 0) {
		return false;
	}

	// один из концов отрезка на луче?
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
	cout << "Введите переменную для задачи \n 1. Сумма чисел равна нулю. \n \n 3.Пересечение отрезка и луча \n 4.Среднее арифметическое \n 5.Стороны многоугольника\n q-чтобы выйти\n";
	string userInput;
	cin >> userInput;
	while (userInput != "q") {
		if (userInput == "1") {
			vector<int> num;
			int hs;
			cout << "Введите промежуток чисел, для завершения ввода введите любую букву\n";
			while (cin >> hs) {
				num.push_back(hs);
			}
			if (sumZero(num)) {
				std::cout << "Сумма чисел равна 0 \n" << std::endl;
			}
			else {
				std::cout << "Сумма чисел не равна 0 \n" << std::endl;
			}
		}
		else if (userInput == "4") {
			int num1, num2, num3;
			cout << "Введите 3 числа для вычисления среднего арифметического \n";
			cin >> num1 >> num2 >> num3;
			cout << "Среднее арифметическое равно " << arifmeticMean(num1, num2, num3)<<'\n';
		}
		else if (userInput == "5") {
			int numSides;
			cout << "Введите количество сторон, для проверки на существование многоугольника \n";
			cin >> numSides;
			vector<int> sides(numSides);
			cout << "Введите длины сторон\n";
			for (int i = 0; i < numSides; i++) {
				cin >> sides[i];
			}
			if (checkPolygon(sides)) {
				cout << "Есть вероятность, что на экране введены цифры, которые могут являться длинами сторон многоугольника\n" << endl;
			}
			else {
				cout << "Вероятность 0, что на экране указаны длины сторон многоугольника\n" << endl;
			}
		}
		else if (userInput == "3") {
			Point a, b, rayOrigin;
			double angle;
			cout << "Введите координаты начала отрезка (x1 y1): ";
			cin >> a.x >> a.y;

			cout << "Введите координаты конца отрезка (x2 y2): ";
			cin >> b.x >> b.y;

			cout << "Введите координаты начала луча (x0 y0): ";
			cin >> rayOrigin.x >> rayOrigin.y;

			cout << "Введите угол направления луча в радианах: ";
			cin >> angle;

			if (position(a, b, rayOrigin, angle)) {
				cout << "Луч пересекает отрезок." << endl;
			}
			else {
				cout << "Луч не пересекает отрезок." << endl;
			}

		}


		cout << "Введите команду: \n";
		std::cin >> userInput;

	}


}