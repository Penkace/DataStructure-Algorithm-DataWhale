/****************************************
  1. 第一种方法是递归，但是这道题目如果测试样例大的会TLE，所以不用递归做，用自底向上dp填表来做能够有效提高Performance
****************************************/

/**************下面是递归的代码***********************/
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        return climbStairs(n-1)+climbStairs(n-2);
    }
};

/**********************************************
  2. 用自底向上dp填表完成，直接AC
**********************************************/
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
