//ȿ����(�ּ�/���, �־�) : n / n2
//��ü ȿ������ �� �� �׷��� ���� �˰��� X
//�˰����� �ſ� ������, ������ ���� O
#include <iostream>
using namespace std;

void insertionSort(int value[], int count)
{
	for (int i = 1; i < count; i++)
	{
		int temp = value[i];
		int j = i;
		while (j > 0 && value[j - 1] > temp)
		{
			value[j] = value[j - 1];
			j--;
		}
		value[j] = temp;
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
	insertionSort(value, 8);
	print(value, 8);
}