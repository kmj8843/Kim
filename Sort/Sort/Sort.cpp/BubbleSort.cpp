//이동 연산 횟수(최선/ 평균 및 최악) : 0 / n2
//효율성(최선, 평균, 최악) : n2
//장점 : 안정성이 유지됨
//단점 : 효율성과 이동 연산 횟수가 느림
//첫번째 부터 count-i번째 까지 각각 큰 수를 뒤로 보냄
#include <iostream>
using namespace std;

void bubbleSort(int value[], int count)
{
	for (int i = count - 1; i >= 0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			if (value[j - 1] > value[j])
			{
				int temp = value[j - 1];
				value[j - 1] = value[j];
				value[j] = temp;
			}
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
	int value[] = { 80,50,70,10,60,20,40,30};
	bubbleSort(value, 8);
	print(value, 8);
}