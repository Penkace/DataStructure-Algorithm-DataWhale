/**************************************************
 过了小数据，但是过全部的时候直接暴栈，参考其他人的答案
**************************************************/
class Solution {
public:
    int get_min(int a,int b){
        return (a<b)?a:b;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int rend = grid.size();
        int cend = grid[0].size();
        vector<vector<int>> a(rend,vector<int>(cend));
        a[0][0] = grid[0][0];
        // 初始化0行和0列的原因是他们左边和上面都没有值
        for(int i=1;i<rend;i++){
            a[0][i]=a[0][i-1]+grid[0][i];
        }
        for(int j=1;j<cend;j++){
            a[j][0] = a[j-1][0]+grid[j][0];
        }
        // 从列开始遍历
        for(int i=1;i<rend;i++){
            for(int j=1;j<cend;j++){
                a[i][j] = get_min(a[i-1][j],a[i][j-1])+grid[i][j];
            }
        }
        return a[rend-1][cend-1];
    }
};
