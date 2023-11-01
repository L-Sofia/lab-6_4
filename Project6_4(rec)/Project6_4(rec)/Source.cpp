#include <iostream>
#include <iomanip>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i) // Генерація
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i) // Виведення
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

int ZeroCount(int* a, int size, int i, int &count) // К-сть елементів, що дорівнюють 0
{
	if (a[i] == 0)
		count++;
	if (i < size - 1)
		return ZeroCount(a, size, i + 1, count);
	else
		return count;
}

int FindMin(int* a, int size, int i, int& min, int& imin) // Знайти мінімальний елемент та його індекс
{
	if (a[i] < min)
	{
		min = a[i];
		imin = i;
	}

	if (i < size - 1)
		return FindMin(a, size, i + 1, min, imin);
	else
		return min;
}

int CalcSumm(int* a, int size,int i, int imin, int s) // Сума усіх елементів після мінімального елементу
{
	s += a[i];
	if (i < size - 1)
		return CalcSumm(a, size, i + 1, imin, s);
	else
		return s;
}

void Sort(int* a, int size, int i, int j)
{
	if (!(a[i] % 2 == 0))
	{
		int minIndex = i;

		for (int j = i + 1; j < size; j++)
		{
			if (!(a[j] % 2 == 0) && abs(a[j]) < abs(a[minIndex]))
				minIndex = j;
		}
		if (minIndex != i) swap(a[i], a[minIndex]);
	}
	if (i < size - 1)
		return Sort(a, size, i + 1, j + 1);
}

int main()
{
	const int n = 15;
	int* a = new int[n];
	int Low = -50;
	int High = 30;
	int x = 0;

	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	cout << "Elements equal zero: " << ZeroCount(a, n, 0, x) << endl;
	cout << "Minimal element: " << FindMin(a, n, 0, a[0], x) << "\n " << "Minimal element index: " << x << endl;
	cout << "Summ of elements after min = " << CalcSumm(a, n, x, x, 0) << endl;
	Sort(a, n, 0, 0);
	cout << "Sorted array: ";
	Print(a, n, 0);

	return 0;
}