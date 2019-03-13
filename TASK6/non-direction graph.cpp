#include<iostream>
#include<stdio.h>
using namespace std;
const int maxvec =100;
const int inf = 65535;
//声明两个变量
typedef int EdgeType;
typedef char VertexType;

typedef struct{
	VertexType vexs[maxvec];//建立顶点表
	EdgeType arc[maxvec][maxvec];// 邻接矩阵，用于存储边的信息 
	int numNodes,numEdges; // 图中当前的顶点数量和边数 
}MGraph;
/*建立无向图的邻接矩阵表示*/
void CreateMGraph(MGraph *Gp){
	// 输入顶点数和边的数量 
	scanf("%d %d",&Gp->numNodes,&Gp->numEdges);
	// 输入每条边的信息 
	for(int i=0;i<Gp->numNodes;i++){
		scanf("%d",&Gp->vexs[i]);
	}
	// 建立变得信息表 
	for(int i=0;i<Gp->numNodes;i++){
		for(int j =0;j<Gp->numNodes;j++){
			if(i==j){
				Gp->arc[i][j] = 0;
			}
			else{
				Gp->arc[i][j] = inf;
			}
		}
	}
	// 输入无向图各条边的信息 
	for(int k=0;k<Gp->numEdges;k++){
		int t1,t2,t3;
		scanf("%d %d %d",&t1,&t2,&t3);
		Gp->arc[t1][t2] = t3;
		Gp->arc[t2][t1] = t3;
	} 
} 
int main(){
	MGraph MG;
	CreateMGraph(&MG);
	cout<<"总共有边"<<MG.numEdges<<"条"<<endl;
	cout<<"总共有点"<<MG.numNodes<<"个"<<endl;
	for(int i=1;i<=MG.numNodes;i++){
		for(int j=i;j<=MG.numNodes;j++){
			if(i!=j&&MG.arc[i][j]!=65535&&MG.arc[i][j]!=0){
				cout<<"从"<<i<<"到"<<j<<"的距离是"<<MG.arc[i][j]<<endl; 
			}
		}
	} 
	return 0; 
} 
