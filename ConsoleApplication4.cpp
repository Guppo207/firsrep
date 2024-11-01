#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;


struct subject {
    string name;    // Название предмета.
    int mark;       // Оценка по предмету.
};


struct student {
    string name;             // Имя студента.
    vector <subject> sessia; // Массив элементов структуры "subject".
};


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите количество учеников в группе: ";
    cin >> n;
    cin.ignore();

    // Определяем названия предметов.
    int p;
    cout << "Введите количество предметов: "<<endl;
    cin >> p;
    cin.ignore();
    vector <string> name(p);
    cout << "Введите названия "<<p<<" предметов: " << endl;
    for (int i = 0; i < p  ; ++i) {
        getline(cin, name[i]);
    }

    vector <student> group;
    for (int i = 0; i < n; ++i) {
        string fullName;
        cout << "Введите имя студента: ";
        getline(cin, fullName);
        vector <subject> results;
        for (int j = 0; j < p; ++j) {
            int mark;
            while (true) {
                cout << "Введите оценку для предмета " << name[j] << ": ";
                cin >> mark;
                cin.ignore();

                // Проверка на корректность ввода.
                if (mark >= 2 && mark <= 5) {
                    subject point2 = { name[j],mark };
                    results.push_back(point2);
                    break;
                }
                else {
                    cout << "Введите корректную оценку." << endl;
                }
            }
        }
        group.push_back(student{ fullName, results });
    }
    //Вводим предмет для счета
    cout << "Введите предмет: ";
    string namepr;
    getline(cin, namepr);
    int q = 0;
    //Считаем кол-во студентов с неудовлетворительной оценкой
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < size(group[i].sessia); j++) {
            if (group[i].sessia[j].name == namepr) {
                if (group[i].sessia[j].mark < 3) {
                    q = q + 1;

                }
            }
        }
    }
    cout <<"Количество студентов с неудовлетворительной оценкой по "<< namepr<<": "<<q;
}