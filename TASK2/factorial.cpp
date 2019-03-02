#include<iostream>
using namespace std;
int fac(int n){
	if(n!=1){
    // 能写成尾递归就写成尾递归
		return n*fac(n-1);
	}	
	return 1;
}
int main(){
	cout<<fac(3)<<endl;
	cout<<fac(4)<<endl;
	return 0;
} 
