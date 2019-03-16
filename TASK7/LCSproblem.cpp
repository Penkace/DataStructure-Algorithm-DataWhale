#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int N = 1005;
int dp[N][N];

int main(){
	string a;
	string b;
	while(cin>>a>>b){
		//getchar(); 
    memset(dp,0,sizeof(dp));
		int l1 = a.size();
		int l2 = b.size();
    // 开始填充数组，dp的状态转移公式比较好理解
		for(int i=1;i<=l1;i++){
			for(int j=1;j<=l2;j++){
        // 如果相等，则等于对角线上一个位置加1
				if(a[i-1] == b[j-1]){
					dp[i][j] = dp[i-1][j-1]+1;
				}
        // 如果不相等，则比较横竖方向较大的那个
				else{
					dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
				}
			}
		}
		printf("%d\n",dp[l1][l2]);
	}
	return 0;
}
