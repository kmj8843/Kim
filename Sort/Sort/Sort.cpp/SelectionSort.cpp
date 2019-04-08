//ȿ���� : n2(���� �˰���)
//�̵� ���� Ƚ�� : n (�ڷ��� ũ�Ⱑ ū ���Ŀ� ������)
//���� : �� ���� �� �̵� ���� Ƚ���� ������ ����, �־��� ��쿡�� ��հ� ���� n2�� ȿ����
//���� : ���� ���� �˰���, ������ ������ X
#include <iostream>
using namespace std;

void selectionSort(int value[], int count)
{
	for (int i = 0; i < count - 1; i++) // ������ �ڷ�� ���� ū ���� ���� ������ count-1��ŭ ����.
	{
		int min = i; //���� ���� index�� �����ϱ� ���� ����
		for (int j = i + 1; j < count; j++) // ���ĵ��� �ʴ� �ڷ� �� ���� ���� ���� ã�� ���� for��
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