#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include <Windows.h>
#include <deque>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;//структура
struct student {

	string fio;
	string group;
	string booknumber;
    int mark1;
    int mark2;
    int mark3;
    int mark4;

};
//функция для сравнения двух средних значений
bool ForSortDouble(const student& ob1, const student& ob2)
{
    double c1;
    double c2;
    
    c1 = ob1.mark1 + c1+ ob1.mark2+ ob1.mark3+ ob1.mark4;
    c2 = ob2.mark1 + c2+ ob2.mark2+ ob2.mark3+ ob2.mark4;

    return c1 / 4 > c2 / 4;
}
// Печать вектора
void print(const deque<student>& deq)
{
    for (auto& pos : deq) {
        cout << "ФИО студента: " << pos.fio << endl;
        cout << "Группа студента: " << pos.group << endl;
        cout << "№ зачетной книжки студента: " << pos.booknumber << endl;
        cout << "Отметки студента: ";
        cout << pos.mark1 << " " << pos.mark2 << " " << pos.mark3 << " " << pos.mark4;
        cout << endl;
    }
}
int main(int argc, const char* argv[]) {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    if (argc != 2) {//проверка введенных аргументов
        cerr << "Что-то не так))";
        return 5;
    }

    const string mode(argv[1]);
    deque<student> students;//создание deque студентов
    if (mode == "keyboard") {//ввод с клавиатуры
        int n;
        cout << "Введите количество студентов: ";
        cin >> n;
        students.resize(n);
        for (int i = 0; i < n; i++) {
            cout << "Введите ФИО студента № " << i+1 << " :";
            cin.ignore();
            getline(cin,students[i].fio);
            cout << endl;
            cout << "Введите группу студента № " << i+1 << " :";
            getline(cin,students[i].group);
            cout << "Введите номер зачетной книжки студента № " <<i+1 << " :";
            cin >> students[i].booknumber;
            cout << "Введите оценки по 4 предметам : ";
            
            cin >> students[i].mark1;
            cin >> students[i].mark2;
            cin >> students[i].mark3;
            cin >> students[i].mark4;

        }
        cout << "--------------" << endl;
        print(students);
        cout << endl;
        cout << "-------------" << endl;
        sort(students.begin(), students.end(), ForSortDouble);
        print(students);
        return 5;
    }
    if (mode == "file") {//чтение из файла
        cout << "Введите имя файла: ";
        string file_name;
        cin >> file_name;
        fstream fin;
        fin.open(file_name);
        if (fin.is_open()) {
            while (!fin.eof()) {
                student emp;
                getline(fin, emp.fio);
                
                getline(fin, emp.group);
               
                getline(fin, emp.booknumber);
                
                fin >> emp.mark1;
                
                fin >> emp.mark2;
                
                fin >> emp.mark3;
                
                fin >> emp.mark4;
                
                fin.ignore();
                students.push_back(emp);
            }
            students.pop_back();
            cout << "count of elements: " << students.size() << endl;
            cout << "------------------------------" << endl;
            print(students);
            cout << endl;
            cout << "---------------" << endl;
            sort(students.begin(), students.end(), ForSortDouble);
            print(students);
        if (!fin.is_open()){
            cout << "file not opened";
        }
        fin.close();
        }
    }
}