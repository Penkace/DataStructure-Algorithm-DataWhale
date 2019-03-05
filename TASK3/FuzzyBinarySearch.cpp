/*******************************************************
在二分查找的基础上做了一个改进，测试用例就是下面给定的数组，肯定是有测试用例过不了的，但是大概的思想是下面那样
*******************************************************/
#include<iostream>
#include<algorithm> 
#include<queue>
#include<stdio.h>
using namespace std;
int arr[10]={2,4,16,24,23,17,25,3,8,11};
void binarySearch(int left,int right,int &num){
  // 二分到最后，应该是含有三个值的，然后输出右边下标对应的值
	if(left==(right-2)){
		cout<<arr[right];
		return;	
	}
	int mid = (right+left)/2;
  // 如果已经找到了这个值就返回其后面一个的长度
	if(arr[mid]==num){
		cout<<arr[mid+1]<<endl;
		return;
	}
  // 递归的时候要把mid也算进去，这样才能保证最后剩下的数值区间长度大于3
	if(arr[mid]<num){ 
		binarySearch(mid,right,num);
	}
	else{
		binarySearch(left,mid,num);
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
