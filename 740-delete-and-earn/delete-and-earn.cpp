class Solution {
public:
    int solver(vector<int>&nums,int i,vector<int>&dp){
        if(i>=nums.size())return 0;
        int curr_val=nums[i];
        int curr_sum=nums[i];
        int index=i+1;
        if(dp[i]!=-1)return dp[i];
        while(index<nums.size() and nums[index]==curr_val){
            curr_sum+=nums[index];
            index++;
        }
        while(index<nums.size() and nums[index]==curr_val+1){
            index++;
        }
        return dp[i]=max(curr_sum+solver(nums,index,dp),solver(nums,i+1,dp));
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        sort(nums.begin(),nums.end());
        return solver(nums,0,dp);
    }
};