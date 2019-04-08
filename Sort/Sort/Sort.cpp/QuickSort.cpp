//평균 비교 횟수 : nlong2n
//효율성(최선, 평균/ 최악) : nlong2n / n2
//장점 : 전체 효율성이 상당히 우수함
//단점 : 최악의 경우 효율성이 떨어짐, 안정성 유지 X
#include <iostream>
using namespace std;

int partitionQuickSort(int value[], int start, int end);

void QuickSort(int value[], int start, int end)
{
	int pivot = 0;
	if (start < end) //start기준 왼쪽, end기준 오른쪽이 정렬이 끝나기 때문에 start<end이면 정렬이 끝남
	{
		pivot = partitionQuickSort(value, start, end);
		QuickSort(value, start, pivot - 1);//pivot기준 왼쪽부터 정렬을 시작
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
		while ((value[left] < value[pivot]) && (left < right)) //left가 pivot보다 큰 값을 찾기위해 계속 움직임, right보다 오른쪽으로 갈 수 없음
			left++;

		while ((value[right] > value[pivot]) && (right < left)) //right가 pivot보다 작은 값을 찾기 위해 계속 움직임, left보다 왼쪽으로 갈 수 없음
			right--;

		if (left < right) //left가 right보다 왼쪽에 위치하고 있다면, 위치를 교환한다.
		{
			int temp = value[left];
			value[left] = value[right];
			value[right] = temp;
		}
	}//right와 left의 위치가 같을때 탈출

	int temp = value[pivot]; //right와 left의 위치가 같음
	value[pivot] = value[right];
	value[right] = value[pivot];

	return right;//반환된 right 또는 left가 다시 pivot이 된다.
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