using namespace std;
#include "Task.h"
#include <random>
#include <iostream>
#include <iomanip>

Task::Task(int ind_1, int ind_2) {
	rows = ind_1;
	numofper = ind_2;
}

void Task::fill() {
	setlocale(0, "RUS");
	cout << "������� ��������, �������� ������ ��������� ������� �������������\n";
	float n;
	for (int i = 0; i < rows * numofper; i++) {
		cin >> n;
		matrA.push_back(n);
	}
	cout << "������� ��������, �������� ������ ��������� ������-������� ��������\n";
	for (int i = 0; i < numofper; i++) {
		cin >> n;
		matrY.push_back(n);
	}
	cout << "������� �������� ��������� �������, ������������ ����� ���������� �� � ������������ ����\n";
	for (int i = 0; i < rows * numofper; i++) {
		cin >> n;
		matricaA.push_back(n);
	}
	cout << "������� �������� �������-������� ��������, ������������ ����� ���������� ������� � �������������� � ������������ ����\n";
	for (int i = 0; i < numofper; i++) {
		cin >> n;
		matricaY.push_back(n);
	}
}

void Task::solve() {
	int nowrow = rows - 1;								// ������� ������
	int nowstolb;										// ������� �������
	for (int i = 0; i < rows; i++) {					// ��������� �� ������ ������, ��� ����� ������ ������� ������� ���������
		float res = 0;									// ��������� ���������� ��� ������� ������
		nowstolb = numofper - 1;						// ������� �������. ���������� ���������� ������ �����, ��� ��� ������ ��� ���
														// ������ ����������� � �� ������ �������� ���� ����� ������ ���������� ������� 
		res = matricaY[nowrow];							// ������������� � res ����� ��������� ��������, �������� ����� ���������,
														// ����������� � ������� ������
		for (int k = 0; k < matricaX.size(); k++) { 	// ��������� �� ��� ��������� ��������� ����������
														// � ������ �� res ��������, ���������� �� �� ������������

		// ������ ��� �������� ������� � ����� ���-�� �������� * ������� ������ + ������� �������
			res -= matricaA[numofper * nowrow + nowstolb] * matricaX[k];
			nowstolb -= 1;
		}
		if (matricaA[numofper * nowrow + nowstolb] != 0) // ������� �� ����������� ��� ����������, ���� �� �� ����� 0
			res /= matricaA[numofper * nowrow + nowstolb];
		nowrow -= 1;									 // �������� ���-�� �����, ��� ����� �������� � ����� ������, ������� ����
		matricaX.push_back(res);						 // ������� ������������ ��������� � ������ � ������������ 
	}
	reverse(matricaX.begin(), matricaX.end());
}

void Task::print() {
	cout << "������� �������������:" << endl;
	int count = 0;
	for (int i = 0; i < matrA.size(); i++) {
		if (count % numofper == 0 && count != 0)
			cout << "\n";
		cout << matrA[i] << setw(12);
		count++;
	}
	cout << endl;
	cout << "������-������� ��������:" << endl;
	for (int i = 0; i < matrY.size(); i++) {
		cout << matrY[i] << endl;
	}
	cout << endl;
	cout << "����������� ��� ������� �������������:" << endl;
	count = 0;
	for (int i = 0; i < matricaA.size(); i++) {
		if (count % numofper == 0 && count != 0)
			cout << "\n";
		cout << matricaA[i] << setw(12);
		count++;
	}
	cout << endl;
	cout << "������-������� �������� ����� ���������� ������� ������������� � ������������ ����:" << endl;
	for (int i = 0; i < matricaY.size(); i++) {
		cout << matricaY[i] << endl;
	}
	cout << endl << "���������� ������:\n";
	for (int i = 0; i < matricaX.size(); i++) {
		cout << "x" << i + 1 << " = " << matricaX[i] << endl;
	}
}



