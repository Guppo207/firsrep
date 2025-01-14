#include <conio.h> 
#include <iostream> 
#include <string>
#include <Windows.h>
using namespace std;
struct vklad
{
	int sum; // Его возраст 
	string fio; // ФИО человека 
	string typeval;
	string stavka;
};
struct ListItem
{
	vklad vkladchik; // Инф поле 
	ListItem* pNext, * pPred;
};
//ListItem *pF1=0; 
struct List
{
	ListItem* pFirst;
};
void addInList(List& list, ListItem* p, bool flag = true)  // flag = true Добавляем в начало списка
{
	if (list.pFirst == 0)
	{
		list.pFirst = p->pNext = p->pPred = p;
	}
	else
	{
		p->pNext = list.pFirst;
		p->pPred = list.pFirst->pPred;
		list.pFirst->pPred->pNext = p;
		list.pFirst->pPred = p;
		if (flag) list.pFirst = p; // Элемент стал первый 

	}
}

void addAfterZad(ListItem* pZad, ListItem* p)
{
	p->pNext = pZad->pNext;
	p->pPred = pZad;
	pZad->pNext->pPred = p;
	pZad->pNext = p;
}

ListItem* myremove(List& list, ListItem* p)
{
	if (list.pFirst == 0 || p == 0) return 0;
	if (list.pFirst->pNext == list.pFirst) // Список состоит из 1 элемента 
	{
		if (p == list.pFirst)
		{
			list.pFirst = 0;
			return p;
		}
		else return 0; // Ошибка 
	}
	if (p == list.pFirst) // Извлекаемый элемент первый 
		list.pFirst = list.pFirst->pNext; // Второй будет первым 
	p->pPred->pNext = p->pNext;
	p->pNext->pPred = p->pPred;
	return p;
}

void print(List  list)
{
	ListItem* p = list.pFirst;
	do
	{
		cout << endl << p->vkladchik.fio << ' ' << p->vkladchik.sum<<' '<<p->vkladchik.typeval<<' '<<p->vkladchik.stavka;
		p = p->pNext;
	} while (p != list.pFirst);
}
int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	char Ch;
	List l1 = { 0 };
	ListItem* p;
	do
	{
		p = new ListItem; // Выделяем память под элемент 
		cout << "\nФИО: ";
		getline(cin, p->vkladchik.fio);
		printf("валюта: ");
		getline(cin, p->vkladchik.typeval);
		printf("процентная ставка: ");
		getline(cin, p->vkladchik.stavka);
		cout << "сумма=";
		cin >> p->vkladchik.sum;
		cin.ignore();
		addInList(l1, p, false); // Добавляю элемент в начало списка 
		cout << "Введите 'y' или 'Y' если хотите ввести еще одного вкладчика,иначе нажмите другую клавишу:";
		Ch = _getche();
	} while (Ch == 'Y' || Ch == 'y');
	cout << endl << "До сортировки";
	print(l1);
	cout << endl;
	do
	{
		// Считаем, что элемент p с минимальным ключом 
		int min = p->vkladchik.sum;

		ListItem* pmin = p;
		// Просматриваем следующие элементы 
		ListItem* p2 = p->pNext;
		while (p2 != l1.pFirst)
		{
			if (p2->vkladchik.sum < min) // Нашли элемент < min, его считаем min  (сортировка по возрасту)
			{
				min = p2->vkladchik.sum;
				pmin = p2;
			}
			p2 = p2->pNext; // Переход к след. элементу 
		}
		if (pmin != p) // Извлекаем pmin и вставляем перед p 
		{
			pmin = myremove(l1, pmin);
			if (pmin == 0)
			{
				cout << endl << "List Error!!!!";
				system("pause");
				return 0;
			}
			if (p == l1.pFirst) addInList(l1, pmin, true);// Вставляем в начало списка
			else addAfterZad(p->pPred, pmin);
		}
		else // Элемент p на своем месте 
			p = p->pNext; // Переход к следующему элементу 
	} while (p->pNext != l1.pFirst);
	cout << endl << "После сортировки";
	print(l1);
}

		