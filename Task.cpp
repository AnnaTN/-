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
	cout << "Введите значения, которыми хотите заполнить матрицу коэффициентов\n";
	float n;
	for (int i = 0; i < rows * numofper; i++) {
		cin >> n;
		matrA.push_back(n);
	}
	cout << "Введите значения, которыми хотите заполнить вектор-столбец значений\n";
	for (int i = 0; i < numofper; i++) {
		cin >> n;
		matrY.push_back(n);
	}
	cout << "Введите значения элементов матрицы, получившиеся после приведения ее к треугольному виду\n";
	for (int i = 0; i < rows * numofper; i++) {
		cin >> n;
		matricaA.push_back(n);
	}
	cout << "Введите элементы вектора-столбца значений, получившиеся после приведения матрицы с коэффициентами к треугольному виду\n";
	for (int i = 0; i < numofper; i++) {
		cin >> n;
		matricaY.push_back(n);
	}
}

void Task::solve() {
	int nowrow = rows - 1;								// Текущая строка
	int nowstolb;										// Текущий столбец
	for (int i = 0; i < rows; i++) {					// Пройдемся по каждой строке, тем самым найдем решение каждого уравнения
		float res = 0;									// Результат вычисления для текущей строки
		nowstolb = numofper - 1;						// Текущий столбец. Записываем переменную внутри цикла, так как каждый раз она
														// должна обновляться и на каждой итерации быть равна номеру последнего столбца 
		res = matricaY[nowrow];							// Первоначально в res будет храниться значение, которому равно уравнение,
														// находящееся в текущей строке
		for (int k = 0; k < matricaX.size(); k++) { 	// Пройдемся по уже найденным значениям переменных
														// и вычтем из res элементы, умноженные на их коэффициенты

		// Индекс для элемента матрицы А равен кол-ву столбцов * текущую строку + текущий столбец
			res -= matricaA[numofper * nowrow + nowstolb] * matricaX[k];
			nowstolb -= 1;
		}
		if (matricaA[numofper * nowrow + nowstolb] != 0) // поделим на коэффициент при переменной, если он не равен 0
			res /= matricaA[numofper * nowrow + nowstolb];
		nowrow -= 1;									 // уменьшим кол-во строк, тем самым перейдем к новой строке, стоящей выше
		matricaX.push_back(res);						 // добавим получившийся результат в вектор с результатами 
	}
	reverse(matricaX.begin(), matricaX.end());
}

void Task::print() {
	cout << "Матрица коэффициентов:" << endl;
	int count = 0;
	for (int i = 0; i < matrA.size(); i++) {
		if (count % numofper == 0 && count != 0)
			cout << "\n";
		cout << matrA[i] << setw(12);
		count++;
	}
	cout << endl;
	cout << "Вектор-столбец значений:" << endl;
	for (int i = 0; i < matrY.size(); i++) {
		cout << matrY[i] << endl;
	}
	cout << endl;
	cout << "Треугольный вид матрицы коэффициентов:" << endl;
	count = 0;
	for (int i = 0; i < matricaA.size(); i++) {
		if (count % numofper == 0 && count != 0)
			cout << "\n";
		cout << matricaA[i] << setw(12);
		count++;
	}
	cout << endl;
	cout << "Вектор-столбец значений после приведения матрицы коэффициентов к треугольному виду:" << endl;
	for (int i = 0; i < matricaY.size(); i++) {
		cout << matricaY[i] << endl;
	}
	cout << endl << "Полученные ответы:\n";
	for (int i = 0; i < matricaX.size(); i++) {
		cout << "x" << i + 1 << " = " << matricaX[i] << endl;
	}
}



