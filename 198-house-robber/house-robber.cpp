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
        vector<int> dp(nums.size()+2,0);
        for(int i=nums.size()-1;i>=0;i--){
            int ans=0;
            dp[i]=ans+=max(nums[i]+dp[i+2],dp[i+1]);
        }
        return max(dp[0],dp[1]);
    }
};