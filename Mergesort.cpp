#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
	if (*a != *b)
	{
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}

void BubbleSort(int a[], int n)/*优化1：如果这一趟都没有发生交换，说明排序完成，可以结束*/
{
	int i;
	int j;
	bool flag = true;
	for (i = 0; flag && i < n - 1; i++)
	{
		flag = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1]){
				swap(&a[j], &a[j + 1]);
				flag = true;
			}
			
		}
	}
}

void BubbleSort2(int a[], int n)/*优化的核心是：最后交换的位置，一定是最后无序的位置，后面的数已经排好序了，*/
{
	int flag = n;
	int k = 0;
	int j = 0;
	while (flag > 0)
	{
		k = flag;
		flag = 0;
		for (j = 0; j < k - 1; j++)
		if (a[j]>a[j + 1])
		{
			swap(&a[j], &a[j + 1]);
			flag = j + 1;
		}
	}
}
void mergeArray(int a[],int low,int mid,int high,int *temp)
{
	int i=0, j=mid+1, k=0;
	while (i <= mid && j <= high)
	{
		if (a[i] >= a[j])
		{
			temp[k++] = a[j++];
		}
		else{
			temp[k++] = a[i++];
		}
	}
	while (i <= mid)
		temp[k++] = a[i++];
	while (j <=high)
		temp[k++] = a[j++];
	for (i = 0; i < k; i++)
		temp[i+low] = a[i];
}
/*void mergeSort(int a[], int low, int high,int *temp )
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		mergeSort(a, low, mid,temp);
		mergeSort(a, mid + 1, high, temp);
		mergeArray(a, low, mid, high, temp);

	}
}
bool MergeSort(int a[],int n)
{
	if (a == NULL || n <= 0)return false;
	int *temp = new int[n];
	if (temp == NULL)return false;
	mergeSort(a,0,n-1,temp);
	delete[] temp;
	return true;
}*/
void print(int a[],int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	putchar('\n');
}
void merge(int array[], int start, int mid, int end, int temp[])
{
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i <= mid)
		temp[k++] = array[i++];
	while (j <= end)
		temp[k++] = array[j++];
	for (i = 0; i < k; i++)
		array[start + i] = temp[i];
	
}
void mergeSort(int array[],int start,int end ,int temp[])
{
	if (array == NULL || temp == NULL || start <0 || end < 0)return;
	int mid=0;
	if (start < end)
	{
		mid = (start + end) / 2;
		mergeSort(array, start, mid, temp);
		mergeSort(array, mid + 1, end,temp);
		merge(array, start, mid, end, temp);
	}
}

void main()
{
	int a[10] = { 34, 65, 54, 11, 235, 22, 21314, 334, 12, 79 };
	print(a, 10);
	int b[10] = { 0 };
	//BubbleSort2(a, 10);
	//print(a, 10);
	mergeSort(a,0,9 ,b);
	//cout << flag << endl;
	print(a, 10);
	system("pause");
}