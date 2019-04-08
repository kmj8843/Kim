//���� �ڷḦ ������ �������� ���� ���� �κ� �������� ���� ���� �� �κ� ���տ� ���� ���� ������ ����
//������ ���� ���İ� ���Ͽ� ����� ȿ����
//ȿ����(�ּ�/���/�־�) : n/n1.25/n2
//������ ���� X
#include <iostream>
using namespace std;

void shellInsertionSort(int[], int, int, int);

void shellSort(int value[], int count)
{
	int interval = count / 2;
	while (interval >= 1)
	{
		for (int i = 0; i < interval; i++)
			shellInsertionSort(value, i, count, interval);
		interval /= 2;
	}
}

void shellInsertionSort(int value[], int start, int end, int interval)
{
	for (int i = start + interval; i < end; i += interval)
	{
		int item = value[i];
		int index = i - interval;
		while ((i >= 0) && (value[index] > item))
		{
			value[index + interval] = value[index];
			index -= interval;
		}
		value[index + interval] = item;
	}
}

void print(int value[], int count)
{
	for (int i = 0; i < count; i++)
		cout << value[i] << endl;
}

int main()
{
	int value[] = { 80,50,70,10,60,20,40,30 };
	shellSort(value, 8);
	print(value, 8);
}