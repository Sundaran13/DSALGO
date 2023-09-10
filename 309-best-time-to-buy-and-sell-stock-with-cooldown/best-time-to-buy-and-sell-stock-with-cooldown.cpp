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
        vector<vector<int>>dp(prices.size()+2,vector<int>(2,0));
        for(int i=prices.size()-1;i>=0;i--){
            
            for(int buy=1;buy>=0;buy--){
                int ans=0;
                if(buy){
                    ans+=max(-prices[i]+dp[i+1][!buy],dp[i+1][buy]);
                }
                else{
                    ans+=max(prices[i]+dp[i+2][!buy],dp[i+1][buy]);
                }
                dp[i][buy]=ans;
            }
        }
        return dp[0][1];
    }
};