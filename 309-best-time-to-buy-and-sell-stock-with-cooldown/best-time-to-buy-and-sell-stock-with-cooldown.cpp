class Solution {
public:
    int solver(vector<int>&prices,int i,bool buy,vector<vector<int>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1)return dp[i][buy];
        int ans=0;
        if(buy){
            ans+=max(-prices[i]+solver(prices,i+1,!buy,dp),solver(prices,i+1,buy,dp));
        }
        else{
            ans+=max(prices[i]+solver(prices,i+2,!buy,dp),solver(prices,i+1,buy,dp));
        }
        return dp[i][buy]=ans;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solver(prices,0,1,dp);
    }
};