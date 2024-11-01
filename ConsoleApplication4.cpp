#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;


struct subject {
    string name;    // �������� ��������.
    int mark;       // ������ �� ��������.
};


struct student {
    string name;             // ��� ��������.
    vector <subject> sessia; // ������ ��������� ��������� "subject".
};


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "������� ���������� �������� � ������: ";
    cin >> n;
    cin.ignore();

    // ���������� �������� ���������.
    int p;
    cout << "������� ���������� ���������: "<<endl;
    cin >> p;
    cin.ignore();
    vector <string> name(p);
    cout << "������� �������� "<<p<<" ���������: " << endl;
    for (int i = 0; i < p  ; ++i) {
        getline(cin, name[i]);
    }

    vector <student> group;
    for (int i = 0; i < n; ++i) {
        string fullName;
        cout << "������� ��� ��������: ";
        getline(cin, fullName);
        vector <subject> results;
        for (int j = 0; j < p; ++j) {
            int mark;
            while (true) {
                cout << "������� ������ ��� �������� " << name[j] << ": ";
                cin >> mark;
                cin.ignore();

                // �������� �� ������������ �����.
                if (mark >= 2 && mark <= 5) {
                    subject point2 = { name[j],mark };
                    results.push_back(point2);
                    break;
                }
                else {
                    cout << "������� ���������� ������." << endl;
                }
            }
        }
        group.push_back(student{ fullName, results });
    }
    //������ ������� ��� �����
    cout << "������� �������: ";
    string namepr;
    getline(cin, namepr);
    int q = 0;
    //������� ���-�� ��������� � �������������������� �������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < size(group[i].sessia); j++) {
            if (group[i].sessia[j].name == namepr) {
                if (group[i].sessia[j].mark < 3) {
                    q = q + 1;

                }
            }
        }
    }
    cout <<"���������� ��������� � �������������������� ������� �� "<< namepr<<": "<<q;
}