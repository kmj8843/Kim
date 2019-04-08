//��� �� Ƚ�� : nlong2n
//ȿ����(�ּ�, ���/ �־�) : nlong2n / n2
//���� : ��ü ȿ������ ����� �����
//���� : �־��� ��� ȿ������ ������, ������ ���� X
#include <iostream>
using namespace std;

int partitionQuickSort(int value[], int start, int end);

void QuickSort(int value[], int start, int end)
{
	int pivot = 0;
	if (start < end) //start���� ����, end���� �������� ������ ������ ������ start<end�̸� ������ ����
	{
		pivot = partitionQuickSort(value, start, end);
		QuickSort(value, start, pivot - 1);//pivot���� ���ʺ��� ������ ����
		QuickSort(value, pivot + 1, end);
	}
}

int partitionQuickSort(int value[], int start, int end)
{
	int left = start;
	int right = end;
	int pivot = end;

	while (left < right)
	{
		while ((value[left] < value[pivot]) && (left < right)) //left�� pivot���� ū ���� ã������ ��� ������, right���� ���������� �� �� ����
			left++;

		while ((value[right] > value[pivot]) && (right < left)) //right�� pivot���� ���� ���� ã�� ���� ��� ������, left���� �������� �� �� ����
			right--;

		if (left < right) //left�� right���� ���ʿ� ��ġ�ϰ� �ִٸ�, ��ġ�� ��ȯ�Ѵ�.
		{
			int temp = value[left];
			value[left] = value[right];
			value[right] = temp;
		}
	}//right�� left�� ��ġ�� ������ Ż��

	int temp = value[pivot]; //right�� left�� ��ġ�� ����
	value[pivot] = value[right];
	value[right] = value[pivot];

	return right;//��ȯ�� right �Ǵ� left�� �ٽ� pivot�� �ȴ�.
}

void print(int value[], int count)
{
	for (int i = 0; i < count; i++)
		cout << value[i] << endl;
}

int main()
{
	int value[] = { 80,50,70,10,60,20,40,30 };
	QuickSort(value, 0, 7);
	print(value, 8);
}