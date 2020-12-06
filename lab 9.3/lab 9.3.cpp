// lab 9.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

struct Zodiac
{
	string surname;
	string zodiac;
	int date[3];
};

void Create(Zodiac* p, const int N);
void Print(Zodiac* p, const int N);
int BinSearch(Zodiac* p, const int N, const string surname);
void PrintSearch(Zodiac* p, const int Num);
void Sort(Zodiac* p, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << " Enter the number of people:"; cin >> N;
	Zodiac* p = new Zodiac[N];

	string zodiak;
	string surname;
	int found;

	int MenuItem;
	do {
		cout << endl << endl << endl;
		cout << "Select an action: " << endl << endl;
		cout << "[1] - keyboard input" << endl;
		cout << "[2] - display of data" << endl;
		cout << "[3] - physical ordering of data" << endl;
		cout << "[4] - binary search for the product by name" << endl;
		cout << endl << endl;
		cout << "[0] - exit and exit of the program" << endl << endl;
		cout << "Enter the value: "; cin >> MenuItem;
		cout << endl << endl << endl;

		switch (MenuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			Sort(p, N);
			break;
		case 4:
			cout << "Enter the search keys:" << endl;
			cin.get();
			cin.sync();
			cout << "Zodiak: "; getline(cin, zodiak);
			cout << endl;
			if ((found = BinSearch(p, N, zodiak)) != -1) 
			{
				cout << "Here is the zodiac sign! \n";
				PrintSearch(p, found + 1);
			}
			else
				cout << "not found" << endl;
			break;
		case 0:
			break;
		default:
			cout << "You entered an incorrect value!"
				"Enter the number - the number of the selected menu item" << endl;
		}
	} while (MenuItem != 0);
	return 0;
}

void Create(Zodiac* p, const int N)
{
	int zodiac;
	int date;
	for (int i = 0; i < N; i++)
	{
		cout << " People # " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << " Zodiac: "; getline(cin, p[i].zodiac);

		cout << " Surname: "; getline(cin, p[i].surname);
		cout << "Date birthday " << i << " Day-Month-Year:\n";
		cin >> p[i].date[0] >> p[i].date[1] >> p[i].date[2];
		cout << endl << endl;
	}
}

void Print(Zodiac* p, const int N)
{
	cout << "=========================================================="
		<< endl;
	cout << "|  #  |     Zodiac    |      Surname     |     date     |"
		<< endl;
	cout << "=========================================================="
		<< endl;

	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(16) << left << p[i].zodiac
			<< "| " << setw(16) << left << p[i].surname
			<< "| " << setw(12) << right << setprecision(2) << p[i].date << " |";
		cout << endl;
		cout << "----------------------------------------------------------";
		cout << endl;
	}
}

int BinSearch(Zodiac* p, const int N, const string zodiak)
{
	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		if (p[m].zodiac == zodiak)
			return m;

		if (p[m].zodiac < zodiak)
			L = m + 1;

		else
			R = m - 1;

	} while (L <= R);
	return -1;
}

void PrintSearch(Zodiac* p, const int Num)
{
	cout << "=========================================================="
		<< endl;
	cout << "|  #  |     Zodiac    |      Surname     |     date      |"
		<< endl;
	cout << "----------------------------------------------------------"
		<< endl;

	cout << "| " << setw(3) << right << Num << " ";
	cout << "| " << setw(16) << left << p[Num].zodiac
		<< "| " << setw(16) << left << p[Num].surname
		<< "| " << setw(12) << right << setprecision(2) << p[Num].date << " |";
	cout << endl;
	cout << "----------------------------------------------------------" << endl;
}

void Sort(Zodiac* p, const int N)
{
	Zodiac tmp;
	for (int i = 0; i < N - 1; i++) // "bubbles" method
		for (int j = 0; j < N - i - 1; j++)
			if (p[j].surname > p[j + 1].surname) {
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
