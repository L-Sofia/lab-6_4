#include <iostream>
#include <iomanip>

using namespace std;

void Create(int* a, const int size, int Low, int High) //Генерування
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);

}

void Print(int* a, const int size) // Виведення
{
	for (int i = 0; i < size; i++)
		cout << a[i] << setw(4);
	cout << endl;
}

int ZeroCount(int* a, int size) // К-сть елементів, що дорівнюють 0
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (a[i] == 0)
			count++;
	return count;
}

int FindMin(int* a, int size, int &imin) //Знаходженя мінімального елементу та його індексу
{
	int min = a[0];

	for (int i = 0; i < size; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
			imin = i;
		}
	}
	return min;
}

int CalcSumm(int* a, int size, int imin) // Cума усіх елементів після мінімального елементу
{
	int s = 0;
	for (int i = imin; i < size; i++)
		s += a[i];
	return s;
}

void Sort(int* a, int size) // Впорядкування лише НЕпарних елементів
{
	for (int i = 0; i < size; i++)
	{
		if (!(a[i] % 2 == 0))
		{
			int minIndex = i; //еквівалентно a[0] з непарних = і
			for (int j = i + 1; j < size; j++)
			{
				if (!(a[j] % 2 == 0) && abs(a[j]) < abs(a[minIndex]))
					minIndex = j;
			}
			if (minIndex != i) swap(a[i], a[minIndex]);
		}
			
	}
}

int main()
{
	const int n = 15;
	int* a = new int[n];
	int Low = -50;
	int High = 30;
	int x = 0;

	Create(a, n, Low, High);
	Print(a, n);
	cout << "Elements equal zero: " << ZeroCount(a, n) << endl;
	cout << "Minimal element: " << FindMin(a, n, x) << "\n " << "Minimal element index: " << x << endl;
	cout << "Summ of elements after min = " << CalcSumm(a, n, x) << endl;
	Sort(a, n);
	cout << "Sorted array: ";
	Print(a, n);

	return 0;
}
