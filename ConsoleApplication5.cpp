#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
using namespace std;
int pros(int a) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int k=0;
    for (int i = 1; i <= (a / 2); ++i) {
        if (a % i == 0) {
            k = k + 1;
        }
    }
    if (k == 1) {
        return 1;
    }
    else {
        return 0;
    }
}
int main(int argc,char* argv[]) {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    const int a(atoi(argv[1]));
    int* chisl;
    srand(time(0));
    int c = 0;
    chisl = new int[a];
    cout << "Массив: ";
    for (int i = 0; i < a; ++i) {
        chisl[i] = rand() % 100;
        cout << chisl[i] << " ";
        if (pros(chisl[i]) == 1) {
            c = c + 1;
        }
    }
    cout << endl;
    cout <<"кол-во числел: "<< c;
    delete[] chisl;
    system("pause");
}
    

