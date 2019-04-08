//기존 자료를 일정한 간격으로 여러 개의 부분 집합으로 나눈 다음 각 부분 집합에 대해 삽입 정렬을 수행
//기존의 삽입 정렬과 비교하여 우수한 효율성
//효율성(최선/평균/최악) : n/n1.25/n2
//안정성 유지 X
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