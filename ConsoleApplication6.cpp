#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
struct tovari // Структура
{
	string name;
	int colvo;
	string price;
};
// Печатаем массив 
void print_tovari(ostream& out, vector<tovari>& TOVARI)
{
	for (auto& pos : TOVARI) {
		out << pos.name << ". " << pos.colvo << ". " << pos.price << ", " << endl;
	}
}
int main(int argc, const char* argv[]) {
	if (argc != 4) {
		cerr << "Error: Use four parameters\n";
		return 5;
	}
	const string mode(argv[1]); // Режим работы (запись или чтение)
	const string open_mode(argv[2]); // Режим открытия файла (текстовый или двоичный)
	const string file_name(argv[3]); // Имя файла
	int n; // Переменная, задающая число элементов массива
	vector<tovari> TOVARI; // массив структур
	if (mode == "write") { // Запись в файл
		// Ввод данных с клавиатуры
		cout << "n="; cin >> n; // Ввод числа элементов
		TOVARI.resize(n); // Задаем размер массива (вектора)
		for (int i = 0; i < n; i++) // Цикл ввода данных о книгах с клавиатуры
		{
			cout << "tovar N=" << (i + 1) << endl;
			cout << "name: ";
			cin.ignore(); // Пропускаем один символ из потока
			getline(cin, TOVARI[i].name);
			cout << "colvo: ";
			cin >> TOVARI[i].colvo;
			cout << "price: ";
			cin >> TOVARI[i].price;
		}
		if (open_mode == "text")
		{
			// Работа с файлом в текстовом режиме 10
				ofstream foutt(file_name); // Открываем файл для записи в текстовом режиме
				foutt << n << endl; // Записываем n в текстовом режиме, далее переход на новую строку
				for (auto& pos : TOVARI) {
					foutt << pos.name << endl << pos.colvo << endl << pos.price<< endl; // Каждая строка с новой строки
				}
			foutt.close(); // Закрываем файл
		}
		else
			if (open_mode == "binary")
			{
				// Работа с файлом в двоичном режиме
				ofstream foutb(file_name, ios::binary); // Открываем файл для записи в двоичном режиме
					foutb.write((char*)&n, sizeof(n)); // Записываем n в двоичном режиме
					for (auto pos : TOVARI) {
						foutb << pos.name << ends << pos.colvo << ends <<pos.price << ends; // После строк вставляем 0, как признак конца
					}
				foutb.close(); // Закрываем файл
			}
	}
	else if (mode == "read") {
		// Чтение из файла
		if (open_mode == "text")
		{
			ifstream fint(file_name); // Открываем файл для чтения в текстового режиме
				if (!fint) // Ошибка файл не открыт
				{
					cout << endl << "Error, file not found" << endl;
					system("pause");
					return 1;
				}
			fint >> n; // Читаем n в Текстовом режиме
			TOVARI.resize(n); // Задаем размер массива
			for (auto& pos : TOVARI) {
				fint.ignore(2, '\n'); // Пропускаем 2 символа с кодами 13 и 10 ('\n')
				getline(fint, pos.name); //
				fint >> pos.colvo;
				fint >> pos.price;
			}
			fint.close(); // Закрываем файл
		}
		else
			if (open_mode == "binary")
			{
				ifstream finb(file_name, ios::binary); // Открываем файл для чтения в двоичном режиме
					if (!finb) // Ошибка файл не открыт
					{
						cout << endl << "Error, file not found" << endl;
						system("pause");
						return 1;
					}
					finb.read((char*)&n, sizeof(n)); // Читаем n в двоичном режиме
					TOVARI.resize(n); // Задаем размер массива
					for (auto& pos : TOVARI) {
						getline(finb, pos.name, '\0'); // Символ '\0' // Читается из потока
						finb.read((char*)&pos.colvo, sizeof(pos.colvo));
						finb.read((char*)&pos.price, sizeof(pos.price));
					}
					finb.close(); // Закрываем файл
			}
		// Печать книг, прочитанных из файла
		print_tovari(cout, TOVARI);
	}
	return 0;
}

