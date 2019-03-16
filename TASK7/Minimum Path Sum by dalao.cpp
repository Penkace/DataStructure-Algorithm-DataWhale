/********************
!!!下面代码是参考的，非本人所写!!!
大佬直接改变了grid的内部数据，根据实际场景进行最便捷的操作
********************/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i=1;i<grid.size();i++) grid[i][0]+=grid[i-1][0];
        for(int j=1;j<grid[0].size();j++) grid[0][j]+=grid[0][j-1];
        for(int i=1;i<grid.size();i++){
            for(int j=1;j<grid[i].size();j++){
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[grid.size()-1][grid[grid.size()-1].size()-1];
    }
};
