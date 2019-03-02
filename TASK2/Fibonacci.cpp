#include<iostream>
#include<stdio.h>
using namespace std;
int fib(int n){
	if(n>=2){
    // 使用尾递归只会占用衡量的内存，避免栈溢出的风险
		return fib(n-1)+fib(n-2);
	}
	return 1; 
}
int main(){
	cout<<fib(4)<<endl; 
	return 0;
}
