//효율성 : n2(느린 알고리즘)
//이동 연산 횟수 : n (자료의 크기가 큰 정렬에 유리함)
//장점 : 비교 연산 및 이동 연산 횟수가 정해져 있음, 최악의 경우에도 평균과 같은 n2의 효율성
//단점 : 느린 정렬 알고리즘, 정렬의 안정성 X
#include <iostream>
using namespace std;

void selectionSort(int value[], int count)
{
	for (int i = 0; i < count - 1; i++) // 마지막 자료는 가장 큰 수만 남기 때문에 count-1만큼 돈다.
	{
		int min = i; //가장 작은 index를 저장하기 위한 변수
		for (int j = i + 1; j < count; j++) // 정렬되지 않는 자료 중 가장 작은 값을 찾기 위한 for문
		{
			if (value[min] > value[j])
				min = j;

			int temp = value[i];
			value[i] = value[min];
			value[min] = temp;
		}
	}
}

void print(int value[], int count)
{
	for (int i = 0; i < count; i++)
		cout << value[i] << endl;
}

int main()
{
	int  value[] = { 80,50,70,10,60,20,40,30 };
	selectionSort(value, 8);
	print(value, 8);
}