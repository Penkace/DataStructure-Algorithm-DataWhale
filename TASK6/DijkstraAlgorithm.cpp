#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
const int N =100;
const int inf = 99999999;
int e[N][N];
int vis[N+1];
int n,m;// 顶点数以及边数 
int dis[N];// 存储距离的数组 
int main(){
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i==j) e[i][j]=0;
				else e[i][j] = inf;
			}
		}
		int t1,t2,t3;// 分别存储起点、终点和距离 
		for(int j=1;j<=m;j++){
			scanf("%d %d %d",&t1,&t2,&t3);
			e[t1][t2] = t3; 
		}
		for(int i=1;i<=n;i++){
			dis[i] = e[1][i];// 取第一个点来做单源最短路径 
		}
		//memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			vis[i] = 0;
		}
		vis[1] =  1;
		// 开始遍历节点，如果i等于1 
		for(int i = 1;i< n;i++){
			int dmin = inf;
			int index = 1;
			for(int j=1;j<=n;j++){
				// 找到dis数组中最小的距离 
				if(vis[j]!=1&&dis[j]<dmin){
					dmin = dis[j];
					index = j;
				}
			}
			vis[index] = 1;
      // 找到后进行松弛操作，relax
			for(int k=1;k<=n;k++){
				if(e[index][k]<inf){
					if(dis[k]>dis[index]+e[index][k]){
						dis[k] = dis[index]+e[index][k];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			printf("%d ",dis[i]);
		}
	} 
	return 0;
}
