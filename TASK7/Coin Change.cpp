/***************************************************
这个DP的方程稍微看了一下其他人的代码，自己随后想了一下，于是写下来
主要是DP[i] = min(dp[i],dp[i-coins[j]]+1)
***************************************************/
class Solution {
public:
    int get_min(int a,int b){
        return a<b?a:b;
    }
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount+1;
        vector<int>dp(amount+1,Max);
        dp[0] = 0;
        int l = coins.size();
        for(int i=1;i<=amount;i++){
            for(int j=0;j<l;j++){
                if(coins[j]<=i){
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};
