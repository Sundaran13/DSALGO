class Solution {
public:
    int solver(vector<int>&nums,int n,int mult,unordered_map<int,int>dp[]){
        if(n<0){
            return mult;
        }
        if(dp[n].find(mult)!=dp[n].end())return dp[n][mult];
        int n1=solver(nums,n-1,mult*nums[n],dp);
        int n2=solver(nums,n-1,nums[n],dp);
        int val=max(n1,max(mult,n2));
        return dp[n][mult]=val;
    }
    int maxProduct(vector<int>& nums) {
        unordered_map<int,int> dp[nums.size()]; 
        return solver(nums,nums.size()-2,nums[nums.size()-1],dp);
    }
};