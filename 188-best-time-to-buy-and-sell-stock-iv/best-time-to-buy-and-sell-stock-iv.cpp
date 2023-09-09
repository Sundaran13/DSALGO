class Solution {
public:
    int maxProfit_func(vector<int>&prices,int i,int c,int buy,int k,vector<vector<vector<int>>>&dp){
        if(i>=prices.size() or c>=k){
            return 0;
        }
        if(dp[i][c][buy]!=-1)return dp[i][c][buy];
        if(buy){
            return dp[i][c][buy]=max(-prices[i]+maxProfit_func(prices,i+1,c,!buy,k,dp),maxProfit_func(prices,i+1,c,buy,k,dp));
        }
        else{
            return dp[i][c][buy]=max(prices[i]+maxProfit_func(prices,i+1,c+1,!buy,k,dp),maxProfit_func(prices,i+1,c,buy,k,dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(k,vector<int>(2,-1)));
        return maxProfit_func(prices,0,0,1,k,dp);
    }
};