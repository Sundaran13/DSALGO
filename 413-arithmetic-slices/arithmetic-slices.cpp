class Solution {
public:
    map<pair<int,int>,int> dp;
    int solver(vector<int>&nums,int i,int diff){
        if(i==nums.size()-1 or nums[i+1]-nums[i]!=diff){
            return 0;
        }
        if(dp.find({i,diff})!=dp.end())return dp[{i,diff}];
        return dp[{i,diff}]=1+solver(nums,i+1,diff);
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3){
            return 0;
        }
        int ans=0;
        for(int i=0;i<nums.size()-2;i++){
            int diff=nums[i+1]-nums[i];
            ans+=solver(nums,i+1,diff);
        }
        return ans;
    }
};