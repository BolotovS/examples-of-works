#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

const int evNothing = 0;//пустое событие
const int evMessage = 100;//непустое событие
const int cmAdd = 1;//добавить 
const int cmDel = 2;//удалить 
const int cmGet = 3;//корректировать
const int cmShow = 4;//посмотреть запись файла
const int cmMake = 0;//выход
const int cmShow2 = 5; //задание 1
const int cmSpra = 6; // задане 2
const int cmSpi = 7;//создание списка
int s = 0;
struct elem
{
	string mes;
	int day;
	int temper;
	elem *pNext;
};

class List
{
	int *ptrtemper = new int[31];
	elem *head, *head2;
	int size;
    public:
	List() //конструктор
	{
		head = nullptr;
		size = 0;
		for (int i = 0; i < 31; i++)
		{
          ptrtemper[i] = 0;
		}
		
	}
	//создание списка
	void AddElement() //создание элемента в списке
	{
		string m;
		cout << "Введите месяц: ";
		cin >> m; cout << endl;
		int d = 0;
		int t;
		for (int i = 0; i < 2; i++)
		{
			d++;
			cout << "Введите температуру " << d << " дня" << endl;
			cin >> t;
			AddItem(m, d, t);
			system("cls");
		}
	}
	void AddItem(string m, int d, int t) //создание элемента
	{
		elem *pElem = new elem;
		pElem->mes = m;
		pElem->day = d;
		pElem->temper = t;
		pElem->pNext = head;
		head = pElem;
		
	}
	void AddItemfile(string m, int d, int t) //создание элемента
	{
		elem *pElem = new elem;
		pElem->mes = m;
		pElem->day = d;
		pElem->temper = t;
		pElem->pNext = head;
		head = pElem;
		s++;
	}
	
	void PrintList() //вывод на экран
	{
		elem *ELEM = head;
		while (ELEM)
		{
			cout << "______________________________________" << endl;
			cout << "Месяц: ";
			printf("%s", ELEM->mes.c_str());
			cout << endl;
			cout << "День: ";
			printf("%d", ELEM->day);
			cout << endl;
			cout << "Температура: ";
			printf("%d", ELEM->temper);
			cout << endl;
			cout << "______________________________________" << endl;
			ELEM = ELEM->pNext;
		}
	}
	void filesozd() //создание и добавление в файл из списка
	{
		ofstream fout;
		int d;
		int tem;
		string me;
		elem *temp = head;
		while (temp)
		{
			elem *pElem = new elem;
			pElem->mes = temp->mes;
			pElem->day = temp->day;
			pElem->temper = temp->temper;
			pElem->pNext = head2;
			head2 = pElem;
			temp = temp->pNext;
			
		}
		elem *tmp = head2;
		fout.open("pogoda.txt");
		while (tmp)
		{
			d = tmp->day;
			tem = tmp->temper;
			me = tmp->mes;
			fout << me;
			fout << endl;
			fout << d;
			fout << endl;
			fout << tem;
			//fout << endl;
			tmp = tmp->pNext;
		}
		fout.close();
	
	}
	void FileRev()//запись из файла в список
	{
		ifstream fout;
		int d;
		int tem;
		string me;
		int j = 0;
		fout.open("pogoda.txt");
		fout.seekg(0, ios::beg);
		while (!fout.eof())
		{
			fout >> me;
			fout >> d;
			fout >> tem;
			AddItem(me, d, tem);
			s++;
		}
		fout.close();
	}
	//конец создания списка
	void Insert(int pos)
	{
		// если параметр отсутствует или равен 0, то запрашиваем его
		if (pos == 0)
		{
			cout << "Введите номер элемента для вставки: ";
			cin >> pos;
		}

		// Позиция от 1 до Count?
		if (pos < 1 || pos > size + 1)
		{
			// Неверная позиция
			cout << "Неверная позиция !!!\n";
			return;
		}
		// Счетчик
		int i = 1;

		// Отсчитываем от головы n - 1 элементов
		elem * Ins = head;

		while (i < pos)
		{
			// Доходим до элемента, 
			// перед которым вставляемся
			Ins = Ins->pNext;
			i++;
		}
		// Создаем новый элемент
		elem * temp = new elem;
		// Вводим данные
		cout << "Введите данные: ";
		cin >> temp->mes;
		cin >> temp->day;
		cin >> temp->temper;
		temp->pNext = Ins;
		Ins->pNext = temp;
		size++;
	}
	void Delete()
	{
		while (head != NULL) //Пока по адресу не пусто
		{
			elem *temp = head->pNext; //Временная переменная для хранения адреса следующего элемента
			delete head; //Освобождаем адрес обозначающий начало
			head = temp; //Меняем адрес на следующий
			                    
		}
		while (head2 != NULL)    
		{
			elem *tmp = head2->pNext;       
			delete head2;                   
			head2 = tmp;
		}
		s = 0;
		
	}
	void Korrect()
	{
		int d;
		int t;
		cout << "Введите день который хотите скорректировать: ";
		cin >> d; cout << endl;
		elem *ELEM = head;
		while (ELEM)
		{
			if (ELEM->day == d)
			{
				cout << "Введите новую температуру дня: ";
				cin >> t; cout << endl;
				ELEM->temper = t;
			}
			ELEM = ELEM->pNext;
		}

	}
	void Dobav(int d)
	{
		string m;
		int dm;
		int t;
		dm = d;
		elem *ELEM = head;
		if (d < 31)
		{
			while (ELEM)
			{
				if (ELEM->day == d) { cout << "этот день уже существует!" << endl; return; }
				ELEM = ELEM->pNext;
			}
			d--;
			ELEM = head;
			while (ELEM)
			{
				if (d == 0) { d++; }
				if (ELEM->day == d || ELEM->day == d+1)
				{ 
				    m = ELEM->mes;
					cout << "Введите температуру дня: ";
					cin >> t; cout << endl;
					elem *pElem = new elem;
					pElem->mes = m;
					pElem->day = dm;
					pElem->temper = t;
					pElem->pNext = head;
					head = pElem;
					s++;
					
				}

				ELEM = ELEM->pNext;
			}
		}
		
	}
	void Udal()
	{
		int a;
		cout << "Введите день предназначенный для удаления: ";
		cin >> a; cout << endl;
		elem *ELEM = head;
		elem *prev = NULL;
		while (ELEM)
		{
			if (ELEM->day == a)
			{
				if (prev)
				{
					prev->pNext = ELEM->pNext;
					ELEM = ELEM->pNext;
					continue;
				}
				else
					head = ELEM->pNext;
			}
			prev = ELEM;
			ELEM = ELEM->pNext;
		}

	}
		
	
	void kop( int d)
	{
		ifstream fout;
		int t;
		int dt;
		int tem;
		string me;
		fout.open("pogoda.txt");
		fout.seekg(0, ios::beg);
		while (!fout.eof())
		{

			fout >> me;
			fout >> dt;
			fout >> tem;
			if (dt == d - 1)
			{
				AddItem(me, dt, tem);
				Dobav(d);
			}
			else
			{
				if (d == 1)
				{
					cout << "Введите температуру дня: ";
					cin >> t; cout << endl;
					AddItem(me, d, t);
					AddItem(me, dt, tem);
					d--;
				}
				else
				{
					AddItem(me, dt, tem);
				}
			}
		}
		fout.close();
	}
	void Srtemp()
	{
		elem *ELEM = head;
		while (ELEM)
		{
			elem *pElem = new elem;
			pElem->mes = ELEM->mes;
			pElem->day = ELEM->day;
			pElem->temper = ELEM->temper;
			pElem->pNext = head2;
			head2 = pElem;
			ELEM = ELEM->pNext;
		}
		int sr;
		int r = 0;
		int i = 0;
		elem *tmp = head2;
		while(tmp)
		{
			ptrtemper[i] = tmp->temper;
			tmp = tmp->pNext;
			i++;
		}
		for (i = 0; i < 31; i++)
		{
			r += ptrtemper[i];
		}
		sr = r / s;
		cout << "Среднее значение: " << sr << endl;
		for (i = 0; i < 31; i++)
		{
			if (ptrtemper[i] > sr)
			{
				
				cout << "Погода поднималась выше среднего значения: " << i+1 << "-го  дня" << endl;
				i - 1;
			}
		}
	}
	void minzn()
	{
		elem *ELEM = head;
		while (ELEM)
		{
			elem *pElem = new elem;
			pElem->mes = ELEM->mes;
			pElem->day = ELEM->day;
			pElem->temper = ELEM->temper;
			pElem->pNext = head2;
			head2 = pElem;
			ELEM = ELEM->pNext;
		}
		int *ptrM = new int [s];
		int r = 0;
		int i = 0;
		int j = 0;
		elem *tmp = head2;
		while (tmp)
		{
			ptrtemper[i] = tmp->temper;
			tmp = tmp->pNext;
			i++;
		}
		for (i = 0; i < s; i++)
		{
			if (ptrtemper[i] < 0)
			{
				ptrM[i] = ptrtemper[i];
				j++;
			}
		}
		cout << "Самый длинный отрезок между днями: " << j << endl;
		cout << "Отрицательныве температуры этих дней:";
		for (i = 0; i < j; i++)
		{
			cout << ptrM[i] << ", ";
		}
		cout << endl;
	}
};

void print_menu() {
	//system("cls"); // очищаем экран
	cout << "Введите число для выполнения операции" << endl;
	cout << "0. Выход" << endl;
	cout << "1. Добавить" << endl;
	cout << "2. Удалить" << endl;
	cout << "3. Корректировать" << endl;
	cout << "4. Просмотреть запись файла" << endl;
	cout << "Задание:" << endl;
	cout << "5. дни, в которые температура поднималась выше средней  за месяц" << endl;
	cout << "6. самый длинный отрезок между днями с отрицательной температурой" << endl;
	cout << "7. Создание базы данных" << endl;
}
struct TEvent
{
	int what;//тип события
	union
	{
		int command;//код команды

		struct

		{
			int message;
			int a;//параметр команды
		};
	};
};
class Dialog : public List
{
protected:
	int EndState; //конечное состояние
public:
	Dialog() //конструктор
	{
		EndState = 0;
	}
	void GetEvent(TEvent &event)
	{
		int k = 0;
		string Op = "01234567"; //содержит коды операций
		string s; //сама операция
		string param;
		char code;
		print_menu();
		cout << '>';
		cin >> s;
		//system("cls"); // очищаем экран
		code = s[0];//первый символ команды
		if (Op.find(code) >= 0)//является ли символ кодом
		{
			event.what = evMessage;
			switch (code)
			{
			case '0':k = 1; event.command = cmMake; break;
			case '1':k = 1; event.command = cmAdd; break;
			case '2':k = 1; event.command = cmDel; break;
			case '3':k = 1; event.command = cmGet; break;
			case '4':k = 1; event.command = cmShow; break;
			case '5':k = 1; event.command = cmShow2; break;
			case '6':k = 1; event.command = cmSpra; break;
			case '7':k = 1; event.command = cmSpi; break;
			}

			//выделяем параметры команды, если они есть
			if (s.length() > 1)
			{
				param = s.substr(1, s.length() - 1);
				int A = atoi(param.c_str());//преобразуем парметр в число 
				event.a = A;//записываем в сообщение
			}
			else
			{
				if (k == 0)
				{
					cout << "Команда введена не правильно!!!" << endl;
					cout << "Введите 1 для продолжения или 0 для выхода" << endl;
					cin >> k;
					if (k == 0)
					{
						ClearEvent(event);
						EndExec();
					}
				}
			}
		}
		else event.what = evNothing;//пустое событие
	}
	virtual int Execute()
	{
		TEvent event; do
		{
			EndState = 0;
			GetEvent(event); //получить событие
			HandleEvent(event); //обработать событие
		} while (!Valid());
		return EndState;
	}
	void EndExec()
	{
		EndState = 1;
	}
	//обработчик событий
	void HandleEvent(TEvent& event)
	{

		if (event.what == evMessage)
		{
			switch (event.command)
			{

			case cmAdd://добавление
				int d;
				cout << "Введите День для добавления: ";
				cin >> d; cout << endl;
				kop(d);
				filesozd();
				Delete();
				ClearEvent(event);
				break;
			case cmDel: //удаление
				FileRev();
				Udal();
				filesozd();
				Delete();
				ClearEvent(event);
				break;
			case cmGet: //корректировка
				FileRev();
				Korrect();
				filesozd();
				Delete();
				ClearEvent(event);
				break;
			case cmShow: //просмотр записи файла
				FileRev();
				PrintList();
				Delete();
				ClearEvent(event);
				break;
			case cmMake:EndExec();//выход
				ClearEvent(event);
				break;
			case cmShow2: //задание 1
				FileRev();
				Srtemp();
				Delete();
				ClearEvent(event);
				break;
			case cmSpra: //задание 2
				FileRev();
				minzn();
				Delete();
				ClearEvent(event);
				break;
			case cmSpi://создание списка
				AddElement();
				filesozd();
				Delete();
				ClearEvent(event);
				break;
			};
		};
	}
	int Valid()
	{
		if (EndState == 0) return 0; else return 1;
	}
	void ClearEvent(TEvent& event)
	{
		event.what = evNothing;//пустое событие
	}

	

};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List l;
	Dialog D;
	D.Execute();
	return 0;
}