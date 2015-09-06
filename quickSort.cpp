#include <iostream>
using namespace std;

int partion(int array[], int low, int high)
{
	int key = array[low];
	int i = low, j = high;
	while (i < j)
	{
		while (i<j && array[j] >= key)j--;
		if (i < j)
			array[i++] = array[j];
		while (i<j && array[i] < key)i++;
		if (i < j)
			array[j--] = array[i];
	}
	array[i] = key;
	return i;

}

void quickSort(int array[],int low,int high)
{
	if (low < high)
	{
		int mid = partion(array, low, high);
		quickSort(array, low, mid - 1);
		quickSort(array, mid + 1, high);
	}
}
void print(int a[],int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void quickSort2(int a[],int low,int high)
{
	if (low < high)
	{
		int i = low;
		int j = high;
		int key = a[low];
		while (i < j)
		{
			while (i<j && a[j]  > key)
				j--;
			if (i < j)
				a[i++] = a[j];
			while (i < j && a[i] <= key)
				i++;
			if (i < j)
			{
				a[j--] = a[i];
			}
		}
		a[i] = key;
		quickSort2(a, low, i - 1);
		quickSort2(a, i + 1, high);
	}
}
void merge(int a[],int start,int mid,int end,int temp[])
{
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end)
	{
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= mid)
		temp[k++] = a[i++];
	while (j <= end)
		temp[k++] = a[j++];
	for (i = 0; i < k; i++)
		a[i + start] = temp[i];
}
void MergeSort(int a[],int low,int high,int temp[])
{
	int mid = 0;
	if (low < high)
	{
		mid = (low + high) / 2;
		MergeSort(a, low, mid, temp);
		MergeSort(a, mid + 1, high, temp);
		merge(a,low,mid,high,temp);
	}
}
void main()
{
	int a[10] = { 24, 998, 5, 645, 345, 4656, 4565, 4, 2, 43 };
	int b[10] = {0};
	print(a, 10);
	MergeSort(a, 0,9,b);
	print(a, 10);
	system("pause");
}