/******************************************************************
第一次接触莱文斯坦距离，之前没有了解过这个概念，于是参考了博客https://blog.csdn.net/lhkaikai/article/details/25186255
莱文斯坦距离是一种两个字符串序列的距离度量，就是一个单词变化到另一个单词的字符编辑距离，如删除、插入和替换；
In mathematics, levab(i,j) = max(i,j) if min(i,j)==0;
                           = min(levab(i-1,j)+1, levab(i,j-1)+1, levab(i-1,j-1)+1)(ai!=bj)
In string approximation matching, the target mostly finds short text matches from very long text, in which case less
differential matches are excepted. For example, auxiliary software for natural language translation based on memory.
When I use dynamic programming to achieve the Levenshtein distance, which can effectively improve the computational efficiency.
And let's talk in code.
******************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;
 // there are three operations so we need to compare the efficiency of these three operations.
int Min(int x,int y,int z){
	return ((x<y)?x:y)<z?((x<y)?x:y):z;
}

//Dynamic programming of the bottom-up mode of Levenshtein distance, storing the distance of repeated calculations into a matrix.
int levenshteinDynamicProgramming(char s[], int s_len, char t[], int t_len)
{
    //构建一个(s_len+1)*(t_len+1)的矩阵d，d[i][j]表示字符串s的前i字符和t的前j个字符的莱文斯坦距离
    int d[s_len+1][t_len+1];
    int i, j;

    //源字符串s到空字符串t只要删除每个字符
    for (i = 0; i <= s_len; i++)
        d[i][0] = i;
    //从空字符s到目标字符t只要添加每个字符
    for (j = 1; j <= t_len; j++)
        d[0][j] = j;
    for (j = 0; j < t_len; j++)
        for (i = 0; i < s_len; i++)
            if (s[i] == t[j])
                d[i+1][j+1] = d[i][j]; //不进行任何操作
            else
            // 这里可以这样理解，ij表示字符串对应的位置，只加j说明是上面的字符串向后移动一位，说明是删除，i+1说明是左边的字符串向后移动一位，说明是插入
                d[i+1][j+1] = Min(d[i][j+1] + 1,  //删除操作
                              d[i+1][j] + 1,  //添加操作
                              d[i][j] + 1 //替换操作
                              );
    printf("使用自底向上方式动态规划实现得到的编辑距离矩阵:\n");
    for (i = 0; i <= s_len; i++) {
        for (j = 0; j <= t_len; j++)
            printf("%3d", d[i][j]);
        printf("\n");
    }

    return d[s_len][t_len];
}

int main(){
	char s[] = "sitting";
	char t[] = "kitten";
	int s_len = 7;
	int t_len = 6;
	int mindis;
	mindis = levenshteinDynamicProgramming(s, s_len, t, t_len);
	printf("莱文斯坦距离是%d",mindis);
	return 0; 
}
