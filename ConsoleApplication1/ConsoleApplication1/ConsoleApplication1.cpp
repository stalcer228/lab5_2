// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <deque>       
#include <iterator>    
#include <algorithm>  
#include <iomanip>
#include <functional>
#include <ctime>


using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");

	deque<long> deque1;
	deque<long> deque2;
	deque<long> deque3;

	deque<long>::iterator it;

	srand(time(NULL));
	for (int i = 0; i < 15; i++)
	{
		deque1.push_back(rand() % 20); // добавляем в дек новые элементы
	}

	cout << "Сгенерированный дек 1: ";
	copy(deque1.begin(), deque1.end(), ostream_iterator<long>(cout, " ")); // вывод на экран элементов дека 1

	std::sort(deque1.begin(), deque1.end(), std::greater<long>());		   // по убыванию
	cout << "\nОтсортированный дек 1 по убыванию: ";
	copy(deque1.begin(), deque1.end(), ostream_iterator<long>(cout, " ")); // вывод на экран элементов дека 1

	int tmpSize = deque1.size();
	int countCond = 0;
	for (int i = 0; i < tmpSize; i++)
	{
		int tmp = deque1.front();
		deque1.pop_front();
		if (tmp < 5)
		{
			deque2.push_front(tmp);
			countCond++;
		}
		else
		{
			deque1.push_back(tmp);
		}
	}

	cout << "\nКол-во элементов удовл. условию < 5: " << countCond;
	//cout << "Дек 1:" << endl;
	//copy(deque1.begin(), deque1.end(), ostream_iterator<long>(cout, " ")); // вывод на экран элементов дека 1
	cout << "\nДек 2:" << endl;
	copy(deque2.begin(), deque2.end(), ostream_iterator<long>(cout, " ")); // вывод на экран элементов дека 2

	std::sort(deque1.begin(), deque1.end(), std::less<long>());				// по возрастанию
	cout << "\nОтсортированный дек 1 по возр :" << endl;
	copy(deque1.begin(), deque1.end(), ostream_iterator<long>(cout, " ")); // вывод на экран элементов дека 1
	std::sort(deque2.begin(), deque2.end(), std::less<long>());				// по возрастанию 
	cout << "\nОтсортированный дек 2 по возр :" << endl;
	copy(deque2.begin(), deque2.end(), ostream_iterator<long>(cout, " ")); // вывод на экран элементов дека 2

	while ((deque1.size() != 0) && (deque2.size() != 0))
	{
		if (deque1.size() != 0)
		{
			deque3.push_front(deque1.front());
			deque1.pop_front();
		}
		if (deque2.size() != 0)
		{
			deque3.push_front(deque2.front());
			deque2.pop_front();
		}
	}

	cout << "\nДек 3 :" << endl;
	copy(deque3.begin(), deque3.end(), ostream_iterator<long>(cout, " ")); // вывод на экран элементов дека 3

	cout << "\nКол-во элементов удовл. условию < 5: " << countCond << endl;

	system("Pause");
}