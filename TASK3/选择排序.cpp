#include<iostream>
using namespace std;
//int alternativesort();
/*
*选择排序法：自己输入数组的长度，然后按从小到大的顺序输出
*/
int main() {
	int i, j, n;
	cout << "Please enter the length of array: ";
	cin >> n;
	int* c=new int [n];
	cout << "Please enter the number: ";
	for (i = 0; i < n; i++) {
		cin >> *(c+i);
	}
	for (i = 0; i < n - 1; i++) {
		int k=i;
		for (j = i + 1; j < n; j++) {
			if (*(c+k) > *(c + j)) {
				*(c + k) = *(c + j);
				*(c + j) = *(c + i);
				*(c + i) = *(c + k);
			}
		}
		*(c + i) = *(c + k);
	}
	for (i = 0; i < n; i++) {
			cout << *(c+i) << " ";
		}
		delete[] c;
		system("pause");
		return 0;
}
