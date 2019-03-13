/********************************************************************
References: https://blog.csdn.net/u013852115/article/details/75947590
*********************************************************************/
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 1<<29
using namespace std;
int in[510],n,m;
bool vis[510];
vector<int> vec[510];
void bfs()
{
    //优先队列存储，保证输出时编号小的靠前
    priority_queue<int,vector<int>,greater<int> > q;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        if(!in[i])//首先将入度为0的点入队（即没有前驱的顶点）
        {
            q.push(i);
            vis[i]=1;
        }
    }
    int flag=0;
    while(!q.empty())
    {
        int top=q.top(); q.pop();//取出top
        
        if(flag)
            printf(" ");//输出
        printf("%d",top);
        flag=1;
        
        for(int i=0;i<vec[top].size();i++)
        {
            int now=vec[top][i];
            in[now]--;//将top的所有直接后继顶点入度-1
            if(!vis[now] && !in[now])//如果这个顶点的入度为0，将它入队
            {
                vis[now]=1;
                q.push(now);
            }
        }
    }
    printf("\n");
}
int main()
{
	// 因为一直输入的都是两个数字，当为空时停止输入 
    while(~scanf("%d %d",&n,&m))
    {
        int u,v;
        memset(in,0,sizeof(in));
        for(int i=1;i<=n;i++)
            vec[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            vec[u].push_back(v);
            in[v]++;//v的入度加一
        }
        bfs();
    }
    return 0;
}
