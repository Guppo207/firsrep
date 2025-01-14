#include <iostream>
#include <vector>
#include <random>
#include "profile.h"
#include <set>
using namespace std;
int main(){
	setlocale(LC_ALL, "RUS");
	vector<int> vec;
	set<int> s;
	mt19937 bas;
	uniform_int_distribution<uint32_t> gen(0, 0xffffffff);
	{
		LogDuration log("Добавить в вектор 100000");
		for (int i = 0; i < 100000; i++) 
			vec.push_back(gen(bas));
		
	}
	{
		LogDuration log("Найти в векторе значения");
		for (int i = 0; i < 100000; i++) 
			find(vec.begin(), vec.end(), gen(bas));
		
	}
	{
		LogDuration log("Удаляем элементы из конца");
		for (int i = 0; i < 100000; i++)
			vec.pop_back();
	}
	{
		LogDuration log("Добавить в set 100000");
		for (int i = 0; i < 100000; i++) 
			s.insert(gen(bas));
	}
	{
		LogDuration log("Найти в set значения");
		for (int i = 0; i < 100000; i++)
			s.find(gen(bas));
	}
	{
		LogDuration log("Удаляем элемент из set");
		for (int i = 0; i < 100000; i++)
			s.erase(gen(bas));
	}
	return 1;
}
