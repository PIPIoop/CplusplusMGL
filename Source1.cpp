#include <iostream>

using namespace std;

bool sumZero(int x0, int x1) {
	int sum=0;
	while (x0 != x1+1) {
		sum += x0;
		x0++;
	}
	return sum == 0;
}
bool sumZero2Option(int x0, int x1) {
	return x0 + x1 == 0;
}

int main(){
	setlocale(LC_ALL, "Russian");
	int x0=1, x1=0;
	cout << "������� ����������  [x0;x1]"<<endl;
	while (x0 > x1) {
		cout << "�����������: x0 ������ ���� ������, ��� x1" << endl;
		cin >> x0 >> x1;
	}
	if (sumZero(x0, x1)) {
		cout << "����� ����� �� ���������� [" << x0 << ":" << x1 << "] ����� ����";
	}
	else
		cout << "����� ����� �� ���������� [" << x0 << ":" << x1 << "] �� ����� ����";

}