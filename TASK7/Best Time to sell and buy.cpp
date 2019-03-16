class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>dp(prices.size()+1,0);
        dp[0] =0;
        int mind = 9999;
        for(int i=1;i<=prices.size();i++){
            mind = prices[i]<mind? prices[i]:mind;
            dp[i] = max(dp[i-1],prices[i]-mind);
        }
        return dp[prices.size()];
    }
};
