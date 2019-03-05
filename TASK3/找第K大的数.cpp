#include<iostream>
#include<algorithm> 
#include<queue>
#include<stdio.h>
using namespace std;
int main(){
	//  如果队列存储的是结构体，我们需要另外定义一个函数去声明 
	priority_queue<int,vector<int>, greater<int> > pq;//维护一个长度为k的优先队列,这个优先队列从小到大排的，当这个队列满了就开始和队头比较  
	int arr[10] = {3,10,24,15,1,7,19,28,20,7};
	int k;
	scanf("%d",&k);
	if(k>10) return -1;
	for(int i=0;i<10;i++){
		if(pq.size()<=k){
			pq.push(arr[i]);
		}
		int tmp = pq.top();
		if(arr[i]>tmp){
			pq.pop();
			pq.push(arr[i]);
		}
	} 
	cout<<pq.top()<<endl;
	return 0;
}
