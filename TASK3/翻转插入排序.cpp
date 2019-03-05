include<iostream>
#include<cstring>
using namespace std;
int main() {
	int j, i, n;
	int *a= new int [6];
	cout << "Please enter array: ";
	for (n = 0; n < 6; n++) {
		cin >> a[n];
	}
	for (j = 2; j < n; j++) {
		int key = a[j];
		i = j - 1;
		while ((i >= 0) && (a[i] < key)) {
			a[i + 1] = a[i];//小的数字往后移一位
			i=i-1;
		}
		a[i + 1] = key;
	}
	for (i = 0; i < n; i++) {
		cout << *(a+i) << " ";
	}
	delete[] a;
	system("pause");
	return 0;
}
