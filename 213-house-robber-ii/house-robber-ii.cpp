class Solution {
public:
    int solver(vector<int>&nums,int i,bool robfirst,vector<vector<int>>&dp){
        if(i>=nums.size() or (i==nums.size()-1 and robfirst))return 0;
        if(dp[i][robfirst]!=-1)return dp[i][robfirst];
        int rob=0,notrob=0;
        if(i==0)rob=solver(nums,i+2,1,dp)+nums[i];
        else rob=solver(nums,i+2,robfirst,dp)+nums[i];
        notrob=solver(nums,i+1,robfirst,dp);
        return dp[i][robfirst]=max(rob,notrob);
    }
    int rob(vector<int>& nums) {
        vector<vector<int>>dp(101,vector<int>(2,-1));
        return solver(nums,0,0,dp);
    }
};