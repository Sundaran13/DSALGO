class Solution {
public:
    int solver(vector<int>&coins,int curr,int amount,vector<vector<int>>&dp){
        if(curr>=coins.size() or amount <= 0){
            return (amount==0)?0: INT_MAX-1;
        }
        if(dp[curr][amount]!=-1)return dp[curr][amount];
        int res=-1;
        if(coins[curr]>amount){
            int dont_take=0+solver(coins,curr+1,amount-0,dp);
            res=dont_take;
        }
        else{
            int take=1+solver(coins,curr+0,amount-coins[curr],dp);
            int dont_take=0+solver(coins,curr+1,amount-0,dp);
            res=min(take,dont_take);
        }
        return dp[curr][amount]=res;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int res=solver(coins,0,amount,dp);
        return (res==INT_MAX -1)?-1:res;
    }
};