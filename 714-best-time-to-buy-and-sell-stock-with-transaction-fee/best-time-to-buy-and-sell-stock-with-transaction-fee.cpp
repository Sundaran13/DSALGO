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
        vector<vector<int>> dp(prices.size()+2,vector<int>(2,0));
        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                if(buy){
                    dp[i][buy]=max(-prices[i]+dp[i+1][!buy],dp[i+1][buy]);
                }
                else{
                    dp[i][buy]=max(prices[i]-fee+dp[i+1][!buy],dp[i+1][buy]);
                }
            }
        }
        return dp[0][1];
    }
};