#pragma once
using namespace std;
#include <vector>
struct Task {
	int numofper;				// ���������� ����������� (����� ��������)
	int rows;					// ���������� �����
	vector<float> matrA;		// ��� ������� ������������� �� ���������� � ������������ ����
	vector<float> matrY;		// ��� �������-������� �������� �� ���������� ������� ������������� � ������������ ����
	vector<float> matricaA;		// ��� ������� ������������� ����� ���������� � ������������ ����
	vector<float> matricaY;		// ��� �������-������� �������� ����� ���������� ������� ������������� � ������������ ����
	vector <float> matricaX;	// ������ �������
	void solve();				// �����, ����������� ������ �������
	Task(int ind_1, int ind_2); // ������������������� �����������, � ������� �������� ������� ��������
	void fill();				// ����� ��� ���������� ��������
	void print();				// ����� ��� ������ �������� ��������� �������� �� �����
};

	