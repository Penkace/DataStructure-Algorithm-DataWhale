#include<cstring>
#include<iosream>
using namespace std;
int insertionsort()
{
	using namespace std;
	int a1[10];
	int j, i,n;
	cout<<"Please enter numbers: ";
	for (n = 0; n <10; n++) {
		cin >> a1[n];
	}
	
	for (j = 2; j < n; j++) {
		int key = a1[j];
		i = j - 1;
		while ((i >= 0) && (a1[i] > key)) {
			a1[i + 1] = a1[i];//把大于key的这个数放到i的后一位,原本的i位置是空的，下面选择到i前面一个位置的数字
			i = i - 1;
		}
		a1[i + 1] = key;//全部比较完了发现key是最大的，就不比了，把原本空的位置放回去
	}
	for (j = 0; j < 10; j++) {
		cout << a1[j]<<" ";
	}
	system("pause");
	return 0;
}
