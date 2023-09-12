class Solution {
public:
    int solver(vector<int>&nums,int curr,int prev,bool positive,vector<vector<vector<int>>>&dp){
        if(curr>=nums.size() or prev>=nums.size()){
            return 0;
        }
        if(dp[curr][prev][positive]!=-1)return dp[curr][prev][positive];
        if(positive){
            if(nums[prev]>nums[curr]){
                return dp[curr][prev][positive]=1+solver(nums,curr+1,curr,!positive,dp);
            }
            else{
                return dp[curr][prev][positive]=solver(nums,curr+1,curr,positive,dp);
            }
        }
        else{
            if(nums[prev]<nums[curr]){
                return dp[curr][prev][positive]=1+solver(nums,curr+1,curr,!positive,dp);
            }
            else{
                return dp[curr][prev][positive]=solver(nums,curr+1,curr,positive,dp);
            }
        }
    }
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(nums.size(),vector<int>(2,-1)));
        return 1+max(solver(nums,1,0,true,dp),solver(nums,1,0,false,dp));
    }
};