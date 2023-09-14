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
        vector<int> dp(nums.size()+1,0);
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=0;i--){
            int curr_val=nums[i];
            int curr_sum=nums[i];
            int index=i+1;
            while(index<nums.size() and nums[index]==curr_val){
                curr_sum+=nums[index];
                index++;
            }
            while(index<nums.size() and nums[index]==curr_val+1){
                index++;
            }
            dp[i]=max(curr_sum+dp[index],dp[i+1]);
            }
        return dp[0];
    }
};