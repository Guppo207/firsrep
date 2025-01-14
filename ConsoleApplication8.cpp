#include <conio.h> 
#include <iostream> 
#include <string>
#include <Windows.h>
using namespace std;

struct vklad // Сотрудник 
{
	string fio; // ФИО 
	double sum; // сумма вклада
	string typeval; // тип валюты
	string stavka;//ставка по вкладу
	
};

struct ListItem // Элемент списка
{
	vklad vkladchik; // Инф поле 
	ListItem* pNext,*pPred; // Указатель на следующий элемент 
};

struct List // Список 
{
	ListItem* pFirst; // Указатель на первый элемент списка 
};


void addFirst(List& list, // Указатель на начало списка 
	ListItem* p) // Указатель на добавляемый элемент (Добавляется текущий элемент, копия элемента не создается)
	{
		p->pNext = list.pFirst;
		list.pFirst = p;
}

bool add(List& list, ListItem* pZad, ListItem* p)// Добавление элемента перед заданным 
{
	// Функция возвращает true при нормальном завершении и false в случае ошибки 
	if (pZad == list.pFirst) // Элемент будет первым 
	{
		p->pNext = list.pFirst;
		list.pFirst = p;
		return true;
	}

	ListItem* pPred = list.pFirst; // Указатель на предыдущий элемент перед pZad 
	while (pPred->pNext != pZad && pPred->pNext)
		pPred = pPred->pNext;
	if (pPred->pNext == 0) return false; // Элемента pZad нет в списке 
	p->pNext = pZad;
	pPred->pNext = p;
	return true;
}
// Удаление любого элемента p из списка 
ListItem* del(List& list, ListItem* p) // Функция возвращает указатель на удаленный элемент
{
 if (list.pFirst == 0) return 0; // Список пуст 
 if (list.pFirst == p) // Удаляем первый элемент 
 {
	 list.pFirst = p->pNext;
	 return p;
 }

 else
 {
  ListItem* pPred = list.pFirst; // Указатель на предыдущий элемент перед p 
  while (pPred->pNext != p && pPred->pNext)
   pPred = pPred->pNext;
  if (pPred->pNext == 0) return 0; // Элемента p нет в списке 
  pPred->pNext = p->pNext;
  return p;
 }

}

int main(int argc, char* argv[])	
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	List list1;
	list1.pFirst = 0; // Список пуст 
	ListItem* p;
	// Ввод списка 
	char Ch; // Переменная для ввода условия продолжения ввода 
	do
	{
		p = new ListItem; // Выделяем память под элемент 
		cout << "\nФИО: ";
		getline(cin, p->vkladchik.fio);
		printf("валюта: ");
		getline(cin, p->vkladchik.typeval);
		cout << "сумма=";
		cin >> p->vkladchik.sum;
		cin.ignore();
		addFirst(list1, p); // Добавляем элемент в начало списка 
		printf("For continue press Y or y else any key! ");
		Ch = _getche(); // Чтение кода клавиши с печатью символа 
	} while (Ch == 'Y' || Ch == 'y');
	// Вывод спика 
	for (ListItem* pi = list1.pFirst; pi; pi = pi->pNext) { // Просмотр списка 
		cout << endl << pi->vkladchik.fio << ' ' <<' ' << pi->vkladchik.typeval << ' ' << pi->vkladchik.sum;
	}

	// Сортировка списка (метод прямого выбора) 
	for (ListItem* pi = list1.pFirst; pi->pNext;)
	{
		// Ищем минимальный элемент в списке 
		double min = pi->vkladchik.sum;
		ListItem* pmin = pi;
		for (ListItem* pj = pi->pNext; pj; pj = pj->pNext)
			if (pj->vkladchik.sum < min)
			{
				min = pj->vkladchik.sum;
				pmin = pj;
			}
		if (pi != pmin) // Минимальный элемент делаем первым, он будет перед pi 
		{
			del(list1, pmin);
			add(list1, pi, pmin);
		}
		else pi = pi->pNext;
	}
	// Печать списка после сортировки 
	cout << "\nAfter sorting:";
	for (ListItem* pi = list1.pFirst; pi; pi = pi->pNext) { // Просмотр списка 
		cout << endl << pi->vkladchik.fio << ' ' << pi->vkladchik.typeval<< ' ' << pi->vkladchik.sum;
	}

	system("pause"); // Останавливаем программу, ждем нажатия любой клавиши 
	return 0;
}
/*ListItem* delFirst(List& list) // Функция возвращает указатель на извлеченный элемент
{
 if (list.pFirst == 0) return 0;
 ListItem* p = list.pFirst;
 list.pFirst = p->pNext;
 return p;

}*/