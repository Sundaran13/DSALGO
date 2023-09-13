class Solution {
public:
    bool solver(vector<int>&nums,int n,int sum,vector<vector<optional<bool>>>&dp){
        if(sum==0){
            return true;
        }
        if(sum<0 or n<=0){
            return false;
        }
        if(dp[n][sum]!=nullopt){
            return dp[n][sum]==true;
        }
        bool result=solver(nums,n-1,sum-nums[n],dp) or solver(nums,n-1,sum,dp);
        dp[n][sum]=result;
        return result;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum%2!=0){
            return false;
        }
        int n=nums.size();
        sum/=2;
        vector<vector<optional<bool>>> dp(n+1,vector<optional<bool>>(sum+1,nullopt));        
        return solver(nums,n-1,sum,dp);
    }
};