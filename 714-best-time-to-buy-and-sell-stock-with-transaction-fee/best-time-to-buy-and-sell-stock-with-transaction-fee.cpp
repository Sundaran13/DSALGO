class Solution {
public:
    int solver(vector<int>&prices,int fee,bool buy,int i,vector<vector<int>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(-prices[i]+solver(prices,fee,!buy,i+1,dp),solver(prices,fee,buy,i+1,dp));
        }
        else{
            return dp[i][buy]=max(prices[i]-fee+solver(prices,fee,!buy,i+1,dp),solver(prices,fee,buy,i+1,dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solver(prices,fee,1,0,dp);
    }
};