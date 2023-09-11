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
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int Amount=amount;
 
        for(int i=0;i<=amount;i++){
            dp[coins.size()][i]=INT_MAX-1;
        }
        for(int i=0;i<coins.size()+1;i++){
            dp[i][0]=0;
        }
        for(int curr=coins.size()-1;curr>=0;curr--){
            for(int amount=0;amount<=Amount;amount++){
                if(curr==coins.size() or amount==0){
                    if(amount==0)dp[curr][amount]=0;
                    else dp[curr][amount]=INT_MAX-1;
                    continue;
                }
                int res=-1;
                if(coins[curr]>amount){
                    int dont_take=0+dp[curr+1][amount+0];
                    res=dont_take;
                }
                else{
                    int take=1+dp[curr+0][amount-coins[curr]];
                    int dont_take=0+dp[curr+1][amount-0];
                    res=min(take,dont_take);
                }
                dp[curr][amount]=res;
                }
            }
        int res=dp[0][amount];
        return (res==INT_MAX -1)?-1:res;
    }
};