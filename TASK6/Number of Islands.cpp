/**************************************
这道题目就没有在Leetcode上做，我单独写出来做
**************************************/
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<queue> 
using namespace std;
const int N =100;
int n,m;// 海岛的长和宽 
char map[N][N];
int vis[N][N];
int dir[4][2] = {{1,0},{0,-1},{0,1},{-1,0}};
struct node{
	int x,y;
};
queue<node> q;
void bfs(int xx,int yy){
	// 终止条件是xx和yy处是'0' 
	if(map[xx][yy]=='0'&&vis[xx][yy]==0) return;
	// 如果不是，则向四周移动 
	for(int k=0;k<4;k++){
		int x = xx + dir[k][0];
		int y = yy + dir[k][1];
		// 判断x,y是否越界并且其是否为海岛，如果是，则要变成水且带进去继续遍历这个节点的下一个节点 
		if(x>=0&&y>=0&&x<n&&y<m&&vis[x][y]==1){
			vis[x][y] = 0;
			map[x][y]='0';
			bfs(x,y);
		}
	} 
}
int main(){
	node start;
	// 所有地方都置位0 
	memset(vis,0,sizeof(vis));
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",&map[i]);
		for(int j=0;j<m;j++){
			// 把海岛的坐标放入队列q中，并且设置vis相应位置为1 
			if(map[i][j]=='1'){
				start.x = i;
				start.y = j;
				// 把这些陆地点放入队列，并且标记为1 
				q.push(start);
				vis[i][j] = 1;
			}
		}
	} 
	// 现在队列中存储的是海岛的坐标以及vis存储海岛坐标的标记 
	node tmp;
	int cnt = 0;
	// 只要队列不为空 
	while(!q.empty()){
		// 取出队头元素 
		tmp = q.front();
		q.pop();
		// 判断队头元素的vis是否为0或者地图上的xy处是否改变为'0' 
		if(vis[tmp.x][tmp.y]==0||map[tmp.x][tmp.y]=='0'){
			continue;
		}
		// 如果不是，说明这是一个新海岛，开始把这个海岛及其附近的岛屿全部变为0标记 
		bfs(tmp.x,tmp.y);
		// 这个是海岛的数量 
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
