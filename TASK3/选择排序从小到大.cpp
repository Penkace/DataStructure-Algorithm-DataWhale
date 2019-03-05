#include<iostream>
using namespace std;
int main(){
	int arr[10] = {2,3,4,10,5,1,7,6,9,0};
	// 选择排序的时间复杂度是O(n^2),从小到大排序 
	for(int i=0;i<10;i++){
		int bubble = arr[i];
		for(int j=i+1;j<10;j++){
			if(bubble>arr[j]){
				arr[i]=arr[j];
				arr[j] = bubble;
				bubble = arr[i];
			}
		}
	}
	for(int i=0;i<10;i++){
		cout<<arr[i]<<endl;
	}
	return 0;
} 
