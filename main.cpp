#pragma once
# include <iostream>
#include "Task.h"
using namespace std;

int main() {
	setlocale(0, "RUS");
	cout << "������ ������ = " << sizeof(Task) << " ����.";
}

//cout << "������� ������� �������: ";
//int order;
//cin >> order;
//Task obj(order, order);
//obj.fill();
//obj.solve();
//obj.print();