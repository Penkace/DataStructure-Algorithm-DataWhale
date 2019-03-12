/************************************************************
 对于BFS，就是每次都向周围进行搜索，直到触发条件
 那么在二维的平面上，移动的方向就有四个，但如果有更多维的比如上或者
 下的时候，建立的方向移动数组就要更多维。广度搜索一般要借助队列来完成。
************************************************************/
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<queue>
using namespace std;
int maze[5][5]={0,1,0,0,0,
0,1,0,1,0,
0,0,0,0,0,
0,1,1,1,0,
0,0,0,1,0};
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};//右下左上的方向
struct node{
	int x,y;
	int step;
	short path[25];
};
queue<node>q;

node bfs(){
	int vis[5][5];
	memset(vis,0,sizeof(vis));
	queue<node>q;
	node now;
	now.x = 0;
	now.y = 0;
	now.step = 0;
	now.path[0]=0;
	vis[0][0]=1;
	q.push(now);
	while(!q.empty()){
		now = q.front();
		q.pop();
		if(now.x==4&&now.y==4){
			return now;
		}
		for(int k=0;k<4;k++){
			int xx = now.x+dir[k][0];
			int yy = now.y+dir[k][1];
			if(xx>=0&&yy>=0&&xx<5&&yy<5&&vis[xx][yy]==0&&maze[xx][yy]==0){
				node temp;
				temp.x=xx;
				temp.y=yy;
				temp.step = now.step+1;
				temp.path[25] = now.path[25];
				temp.path[temp.step]=k;
				q.push(temp);
			}
		}
	}
	return now;
}
int main(){
	node res = bfs();
	int x,y;
	for(int i=0;i<=res.step;i++){
		x+=dir[res.path[i]][0];
		y+=dir[res.path[i]][1];
		cout<<"("<<x<<" "<<y<<")"<<endl;
	}
	return 0;
}
