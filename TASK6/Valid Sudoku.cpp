/*************************************
刚开始想这道题目的时候以为是要往数独表里面
填数字，并且保证每一行每一列都只有1-9个数字
并且每个数字出现的次数都是一次，然后每个小9
放个也必须遵循数字只出现一次。
想了5分钟发现做不出来，于是参考其他朋友的
博客，发下并需要里面填数字...只是判断每一行
每一列是否有数字重复，看了一些博客发现大家的
做法都大同小异，先分开行和列，对行和列分别检
查，之后再检查九个方格，，检查九个方格的时候，
通过0,3,6来确定行列的坐标，r,c作为起始的坐标，
i,j是对应的行列坐标，在下面的代码中先检查竖向
的方格，竖着的方格检查结束才横向移动再竖向检
查。
*************************************/
class Solution {
public:
    bool isValidSudoku(const vector<vector<char>>& board) {
        bool used[9];
        for (int i = 0; i < 9; ++i) {
            fill(used, used + 9, false);
            for (int j = 0; j < 9; ++j) // 检查行
                if (!check(board[i][j], used))
                    return false;
            fill(used, used + 9, false);
            for (int j = 0; j < 9; ++j) // 检查列
                if (!check(board[j][i], used))
                    return false;
        }
        for (int r = 0; r < 3; ++r) // 检查9 个子格子
            for (int c = 0; c < 3; ++c) {
                fill(used, used + 9, false);
                for (int i = r * 3; i < r * 3 + 3; ++i)
                    for (int j = c * 3; j < c * 3 + 3; ++j)
                        if (!check(board[i][j], used))
                            return false;
            }
        return true;
    }
    bool check(char ch, bool used[9]) {
        if (ch == '.') return true;
        if (used[ch - '1']) return false;
        return used[ch - '1'] = true;
    }
};
