//�̵� ���� Ƚ��(�ּ�/ ��� �� �־�) : 0 / n2
//ȿ����(�ּ�, ���, �־�) : n2
//���� : �������� ������
//���� : ȿ������ �̵� ���� Ƚ���� ����
//ù��° ���� count-i��° ���� ���� ū ���� �ڷ� ����
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