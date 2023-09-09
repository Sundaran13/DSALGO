class Solution {
public:
    int find(vector<int>&cost,int i,vector<int>&dp){
        if(i>=cost.size())return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=min(cost[i]+find(cost,i+1,dp),cost[i]+find(cost,i+2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+2,0);
        for(int i=cost.size()-1;i>=0;i--){
            dp[i]=min(cost[i]+dp[i+1],cost[i]+dp[i+2]);
        }
        return min(dp[0],dp[1]);
    }
};