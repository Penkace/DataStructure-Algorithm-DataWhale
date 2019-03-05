#include<iostream>
#include<algorithm> 
#include<queue>
#include<stdio.h>
using namespace std;
int arr[10]={2,4,16,24,23,17,25,3,8,11};
void binarySearch(int left,int right,int &num){
	if(left>right){
		cout<<"No Number";
		return;	
	}
	int mid = (right+left)/2;
	if(arr[mid]== num){
		cout<<"Find The Number in Array";
	}
	else{
		if(arr[mid]<num){
			binarySearch(mid+1,right,num);
		}
		else{
			binarySearch(left,mid-1,num);
		}
	}
}
int main(){
	int len = 10;
	int fid;
	scanf("%d",&fid);
	sort(arr,arr+10);
	binarySearch(0,len,fid);
	return 0;
}
