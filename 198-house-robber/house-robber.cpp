class Solution {
public:
    int solver(vector<int>&nums,int i,vector<int>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int ans=0;
        return dp[i]=ans+=max(nums[i]+solver(nums,i+2,dp),solver(nums,i+1,dp));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return max(solver(nums,0,dp),solver(nums,1,dp));
    }
};