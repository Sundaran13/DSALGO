class Solution {
public:
    int solver(vector<int>&coins,int amount,vector<int>&dp){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return -1;
        }
        if(dp[amount]!=-1)return dp[amount];
        int res=INT_MAX-1;
        for(auto it:coins){
            int sub_res=solver(coins,amount-it,dp);
            if(sub_res!=-1){
                res=min(res,1+sub_res);
            }
        }
        return dp[amount]=res;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        return solver(coins,amount,dp)==INT_MAX-1?-1:solver(coins,amount,dp);
    }
};