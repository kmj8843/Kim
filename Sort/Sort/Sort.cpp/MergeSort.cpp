//이동 및 비교 연산 횟수(최선, 평균, 최악) : nlogn2
//이동, 비교 연산 횟수, 효율성이 매우 우수함
//추가 메모리 공간 필요, 자료의 이동 횟수가 많음
//정렬 대상이 되는 자료의 크기가 큰 경우 시간적 낭비가 심해지므로 이 경우 배열 대신 연결 리스트를 사용하여 이동 양을 줄이는 최적화 기법 필요
//안정성 유지 O
#include <iostream>
using namespace std;

void mergeSortInternal(int[], int[], int, int, int);
void print(int[], int);
void mergeSort(int value[], int buffer[], int start, int end)
{
	int middle;
	if (start < end)
	{
		middle = (start + end) / 2;
		mergeSort(value, buffer, start, middle);
		mergeSort(value, buffer, middle + 1, end);

		mergeSortInternal(value, buffer, start, middle, end);
	}
}

void mergeSortInternal(int value[], int buffer[], int start, int middle, int end)
{
	int i = start;
	int j = middle + 1;
	int k = start;

	while (i <= middle && j <= end)
	{
		if (value[i] <= value[j])
			buffer[k] = value[i++];
		else
			buffer[k] = value[j++];
		k++;
	}

	if (i > middle)
		for (int t = j; t <= end; t++, k++)
			buffer[k] = value[t];
	else
		for (int t = i; t <= middle; t++, k++)
			buffer[k] = value[t];

	for (int i = start; i <= end; i++)
		value[i] = buffer[i];

	print(value, 8);
}

void print(int value[], int count)
{
	for (int i = 0; i < count; i++)
		cout << value[i] << " ";
	cout << endl;
}

int main()
{
	int value[] = { 80,50,70,10,60,20,40,30 };
	int* buffer = new int[8];
	mergeSort(value, buffer, 0, 7);
	delete[] buffer;
	print(value, 8);
}