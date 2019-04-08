//�̵� �� �� ���� Ƚ��(�ּ�, ���, �־�) : nlogn2
//�̵�, �� ���� Ƚ��, ȿ������ �ſ� �����
//�߰� �޸� ���� �ʿ�, �ڷ��� �̵� Ƚ���� ����
//���� ����� �Ǵ� �ڷ��� ũ�Ⱑ ū ��� �ð��� ���� �������Ƿ� �� ��� �迭 ��� ���� ����Ʈ�� ����Ͽ� �̵� ���� ���̴� ����ȭ ��� �ʿ�
//������ ���� O
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