#include <iostream>
#include <Windows.h>

using namespace std;

void Create(int** mas, const int ROW_COUNT, const int COL_COUNT, const int HIGH, const int LOW);
void Print(int** mas, const int ROW_COUNT, const int COL_COUNT);
void Input(int** mas, const int ROW_COUNT, const int COL_COUNT);
bool Count(int** mas, const int ROW_COUNT, const int COL_COUNT, int& count);
bool IsMinInRows(int** mas, const int n, const int k, const int ROW_COUNT, const int COL_COUNT);
bool IsMaxInCols(int** mas, const int n, const int k, const int ROW_COUNT, const int COL_COUNT);
void Saddle_point(int** mas, const int ROW_COUNT, const int COL_COUNT);

int main()
{
	srand(time(NULL));	

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int ROW_COUNT; cout << "RowCount = "; cin >> ROW_COUNT;
	int COL_COUNT; cout << "ColCount = "; cin >> COL_COUNT;
	const int HIGH = 20;
	const int LOW = 10;

	int** mas = new int* [ROW_COUNT];
	for (int i = 0; i < ROW_COUNT; i++)
		mas[i] = new int[COL_COUNT];

	Create(mas, ROW_COUNT, COL_COUNT, HIGH, LOW);
	Input(mas, ROW_COUNT, COL_COUNT);
	Print(mas, ROW_COUNT, COL_COUNT);
	int count = 0;
	if (Count(mas, ROW_COUNT, COL_COUNT, count))
		cout << "Кількість від'ємних елементів у тих рядках, які містять хоча б один нульовий елемент: " << count << "\n";
	else 
		cout << "Немає від'ємних елементів" << "\n" << "\n";

	Saddle_point(mas, ROW_COUNT, COL_COUNT);
	cout << "\n";

	for (int i = 0; i < ROW_COUNT; i++)
		delete[] mas[i];
	delete[] mas;

}
void Create(int** mas, const int ROW_COUNT, const int COL_COUNT, const int HIGH, const int LOW)
{
	for (int i = 0; i < ROW_COUNT; i++)
		for (int j = 0; j < COL_COUNT; j++)
			mas[i][j] = LOW + rand() % (HIGH - LOW + 1);
}
void Print(int** mas, const int ROW_COUNT, const int COL_COUNT)
{
	for (int i = 0; i < ROW_COUNT; i++)
	{
		for (int j = 0; j < COL_COUNT; j++)
		{
			cout << mas[i][j] << '\t';
		}
		cout << '\n';
	}
}
void Input(int** mas, const int ROW_COUNT, const int COL_COUNT)
{
	for (int i = 0; i < ROW_COUNT; i++)
	{
		for (int j = 0; j < COL_COUNT; j++)
		{
			cout << "mas[" << i << "][" << j << "] = "; cin >> mas[i][j];
		}
		cout << "\n";
	}
}
bool Count(int** mas, const int ROW_COUNT, const int COL_COUNT, int& count)
{
	bool result = false;
	count = 0;
	int k;
	for (int i = 0; i < ROW_COUNT; i++)
	{
		k = 0;
		for (int j = 0; j < COL_COUNT; j++)
			if (mas[i][j] == 0)
			{
				result = true;
				k++;
				break;
			}

			if (k > 0)
			{
				for (int j = 0; j < COL_COUNT; j++)
					if (mas[i][j] < 0)
						count++;
			}
	}
	return result;
}
bool IsMinInRows(int** mas, const int n, const int k, const int ROW_COUNT, const int COL_COUNT)
{
	for (int j = 0; j < COL_COUNT; j++)
		if (mas[n][j] < mas[n][k])
		{
			return false;
		}
			return true;
}
bool IsMaxInCols(int** mas, const int n, const int k, const int ROW_COUNT, const int COL_COUNT)
{
	for (int i = 0; i < ROW_COUNT; i++)
		if (mas[i][k] > mas[n][k])
		{
			return false;
		}
			return true;
}
void Saddle_point(int** mas, const int ROW_COUNT, const int COL_COUNT)
{
	cout << "saddle point: ";
	cout << "\t" << "number" << "\t" << "row" << "\t" << "col" << "\n";
	int number = 0;
	for (int n = 0; n < ROW_COUNT; n++)
		for (int k = 0; k < COL_COUNT; k++)
			if (IsMaxInCols(mas, n, k, ROW_COUNT, COL_COUNT) && IsMinInRows(mas, n, k, ROW_COUNT, COL_COUNT))
			{
				cout << "\t" << "\t"  << ++number << "\t" << n << "\t" << k << "\n";
			}
}