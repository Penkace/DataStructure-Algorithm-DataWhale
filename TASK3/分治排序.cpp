#include<iostream>
using namespace std;
/*
*分治排序法
*/
void  Merge(int *array, int low, int middle, int high) {
	int *A = new int[high - low + 1];
	int i = low;
	int j = middle + 1;
	int k = 0;
	while (i <= middle && j <= high)
	{
		if (array[i] <= array[j])
			A[k++] = array[i++];
		else
			A[k++] = array[j++];
	}
	while (i <= middle)
		A[k++] = array[i++];
	while (j <= high)
		A[k++] = array[j++];
	for (i = low; i <= high; i++)
		array[i] = A[i - low];
	delete[] A;
}

void MergeSort(int *array, int low, int high) {
	int middle;
	if (low < high) {
		middle = (low + high) / 2;
		MergeSort(array, low, middle);
		MergeSort(array, middle + 1, high);
		Merge(array, low, middle, high);
	}
}
int main() {
	cout << "Enter the array: ";
	int n;
	cin >> n;
	int* array = new int[n];
	cout << endl << "enter data: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	MergeSort(array, 0, n - 1);
	cout << "after merge: " << endl;
	for (int j = 0; j < n; j++) {
		cout << array[j] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
