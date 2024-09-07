#include <iostream>

using namespace std;

bool equalProduct(int x0, int x1, int x2, int x3) {
	if (((x0 < 0 && x1>0) || (x0 > 0 && x1 < 0)) && ((x2 < 0 && x3>0) || (x2 > 0 && x3 < 0)) || (x0>=0 && x1>=0 && (x2>=0 && x3>=0 || x2<0 && x3<0)) || (x0 < 0 && x1 < 0 && (x2 > 0 && x3 > 0 || x2 < 0 && x3 < 0))) {
		if (x0 / x3 == x2 / x1 && x0 / x2 == x3 / x1)
			return true;
	}
	return false;

}

int main() {
	setlocale(LC_ALL, "Russian");
	int x0, x1, x2, x3;
	cout << "Введите 4 числа:" << endl;
	cin >> x0 >> x1 >> x2 >> x3;
	if (equalProduct(x0, x1, x2, x3)) {
		cout << "Произведение " << x0 << " * " << x1 << " = " << x2 << " * " << x3;
	}
	else
		cout << "Произведение " << x0 << " * " << x1 << " НЕ равняется " << x2 << "*" << x3;	
}