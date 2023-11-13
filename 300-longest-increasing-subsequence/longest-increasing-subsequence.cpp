class Solution {
public:
    int dp[2501][2501];
    int solver(vector<int>&nums,int prev,int i){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int take=0,not_take=0;
        if(prev==-1 or nums[i]>nums[prev]){
            take=1+solver(nums,i,i+1);
        }
        not_take=solver(nums,prev,i+1);
        return dp[i][prev+1]=max(take,not_take);

    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return solver(nums,-1,0);
    }
};