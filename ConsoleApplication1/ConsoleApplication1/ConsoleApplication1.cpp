// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <deque>       
#include <iterator>    
//#include <fstream> 
#include <algorithm>  
#include <iomanip>
#include <functional>


using namespace std;

template <typename deque>
void deldeque(deque& my_deque)
{
	typename deque::iterator i = my_deque.begin();
	while ((i = find_if(i, my_deque.end(), pred)) != my_deque.end())
		my_deque.erase(i++);
}

template <class InputIterator, class Predicate>
void search(InputIterator first, InputIterator last, Predicate Pred, const string& Str)
{

	auto p = find_if(first, last, Pred);

	if (p == last) {
		cout << Str << "Нужных элементов нет \n" << endl;
	}
	else {
		cout << "Элемент найден \n";
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	//deque<long>::iterator it;
	deque<long> deque1;
	deque<long> deque2;
	deque<long> deque3;

	deque<long>::iterator it;


	for (int i = 0; i < 15; i++)
	{
		deque1.push_back(rand() % 20); // добавляем в дек новые элементы
	}

	cout << "\nСгенерированный дек: ";
	copy(deque1.begin(), deque1.end(), ostream_iterator<long>(cout, " ")); // вывод на экран элементов дека
	std::sort(deque1.begin(), deque1.end(), std::greater<long>());
	copy(deque1.begin(), deque1.end(), ostream_iterator<long>(cout, " ")); // вывод на экран элементов дека
	system("Pause");
	std::sort(deque1.begin(), deque1.end(), std::less<long>());
	copy(deque1.begin(), deque1.end(), ostream_iterator<long>(cout, " ")); // вывод на экран элементов дека

	 /*for (auto it = deque1.rbegin(); it != deque1.rend(); ++it) // сортировка
	 {
		 cout << it -> first << " => " << it -> second << endl;
	 }*/
	system("pause");
}

