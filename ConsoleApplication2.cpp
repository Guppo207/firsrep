#include <iostream>// 2 задача без include <vector>
#include <ctime>
using namespace std;
int main1(){
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	size_t m, n;
	cout << "Введите количество строк и количество столбцов матрицы:" << endl;
	cin >> m >> n;
	int** matrix;
	matrix = new int* [m];
	for (int i = 0; i < m; ++i) {
		matrix[i] = new int[n];
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			matrix[i][j] = rand() % 100;//случайные числа от 0 до 100
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[j][i] << " ";
		}
		cout << endl;
	}
	//////////////////////////////
	for (int i = 0; i < m; ++i) {/////очищение памяти по массивам внутри массива
		delete[] matrix[i];
	}
	delete[] matrix;//очищение памяти главного массива
	return 0;
}