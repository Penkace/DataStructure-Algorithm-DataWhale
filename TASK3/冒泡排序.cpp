#include<iostream>
#include<algorithm> 
using namespace std;
int main(){
	int arr[10] = {2,3,4,10,5,1,7,6,9,0};
	// 冒泡排序的时间复杂度是O(n^2),从小到大排序 
	for(int i=0;i<9;i++){
		for(int j=i+1;j<10;j++){
			if(arr[i]>arr[j]){
				swap(arr[i],arr[j]);
			}
		}
	}
	for(int i=0;i<10;i++){
		cout<<arr[i]<<endl;
	}
	return 0;
} 
