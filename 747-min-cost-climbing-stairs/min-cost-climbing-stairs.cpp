class Solution {
public:
    int find(vector<int>&cost,int i,vector<int>&dp){
        if(i>=cost.size())return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=min(cost[i]+find(cost,i+1,dp),cost[i]+find(cost,i+2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        return min(find(cost,0,dp),find(cost,1,dp));
    }
};