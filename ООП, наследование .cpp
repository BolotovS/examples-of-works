#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <math.h>
using namespace std;

class Number // базовый класс
{
public:
	virtual void print() = 0;
};

class PAIR : public Number // производный класс
{
protected: // спецификатор доступа к элементу value
	int first;
	int second;
public:
	void set_first(int t) { first = t; };
	void set_second(int t) { second = t; };
	int get_first() { return first; };
	int get_second() { return second; };
	void Sozd() // функция создания чисел
	{
		cout << "Введите первое число: \t";
		cin >> first;
		cout << "Введите ворое число: \t";
		cin >> second;
	}
	void print() {
		cout << "(" << get_first() << "." << get_second() << ")";
	}
	void sravnenie(PAIR p1, PAIR p2)
	{
		if (p1.first > p2.first)
		{
			cout << " Сравнение: р1 Больше р2" << endl;
		}
		else
		{
			cout << "p1 Меньше p2. Переход к другому сравнению" << endl;
			if (p1.first == p2.first &&p1.second > p2.second)
			{
				cout << "p1.first==p2.first && p1.second>p2.second = Сравнение выполнилось" << endl;
			}
			else
			{
				cout << "p1.first==p2.first && p1.second>p2.second = Сравнение  не выполнилось" << endl;
			}
		}
	}


};
class fraction : public PAIR
{
public:
	void Printfracton()
	{

	}
	void sravnenie(fraction f1, fraction f2)
	{
		if ((f1.second == 0) || (f2.second == 0))
		{
			cout << "на 0 делить нельзя! введите дробь заного" << endl;
			f1.Sozd();
			f2.Sozd();
			f1.sravnenie(f1, f2);
		}
		else {
			if (f1.second*f2.second > 0)
			{
				(f1.first*f2.second > f2.first*f1.second);
			}
			else (f1.first*f2.second < f2.first*f1.second);
			if (f1.first > f2.first)
			{
				cout << "дробь 1 больше дроби 2" << endl;
			}
			else
			{
				cout << "дробь 2 больше дроби 1" << endl;
			}
		}
	}
};

class Vector
{
private:
	Number * *beg; //указатель на первый элемент вектора
	int size; //размер вектора
	int cur; //текущая позиция
public:
	Vector() //конструктор без параметров
	{
		beg = 0;
		size = 0;
		cur = 0;
	}
	Vector(int n) // конструктор c параметрами
	{
		beg = new Number*[n];
		cur = 0;
		size = n;
	}
	~Vector() // деструктор
	{
		if (beg != 0)delete[] beg;
		beg = 0;
	}
	void Add(Number *p)
	{
		if (cur < size)
		{
			beg[cur] = p;
			cur++;
		}
	}
	friend ostream& operator <<(ostream&out, const Vector&v)
	{
		if (v.size == 0)
		{
			out << "Empty" << endl;
		}
		Number **p = v.beg; //указатель на указатель типа number
		for (int i = 0; i < v.cur; i++)
		{
			(*p)->print();
			p++;
		}
		return out;
	}
};

int main()
{

	setlocale(LC_ALL, "Rus");
	Vector v(5); //создание объекта класса вектора
	cout << "Ввести числа 1-й пары " << endl;
	PAIR p1; //создание объекта класса pair
	p1.Sozd();
	cout << "Ввести числа 2-й пары " << endl;
	PAIR p2; //создание объекта класса pair
	p2.Sozd();
	cout << endl;
	cout << "Пары р1 и р2" << endl;
	p1.print();
	cout << "________________________________________________" << endl;
	cout << endl;
	p2.print();
	cout << endl;
	cout << "Методы сравнения пар " << endl;
	p1.sravnenie(p1, p2);
	cout << "________________________________________________" << endl;
	fraction f1; //создание объекта класса fraction
	fraction f2; //создание объекта класса fraction
	f1.Sozd();
	f2.Sozd();
	cout << endl << endl;
	f1.sravnenie(f1, f2);
	cout << "_________Класс ВЕКТОР___________" << endl;
	Number*p = &p1;
	v.Add(p);
	p = &p2;
	v.Add(p);
	cout << v;
	system("pause");
	return 0;
}