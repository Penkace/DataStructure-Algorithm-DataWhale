/***********************************************
利用动态规划来解决爬楼梯的问题
***********************************************/

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int* record = new int[n+1];
        record[0] = 0;
        record[1] = 1;
        record[2] = 2;
        for(int i=3;i<=n;i++){
            record[i] = record[i-1]+record[i-2];
        }
        return record[n];
    }
};
