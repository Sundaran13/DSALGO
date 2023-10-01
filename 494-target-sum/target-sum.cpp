class Solution {
public:
    map<pair<int,int>,int> dp;
    int solver(vector<int>&nums,int target,int index,int total){
        if(index>=nums.size()){
            if(total==target)return 1;
            else return 0;
        }
        if(dp.find({index,total})!=dp.end())return dp[{index,total}];
        int positive=solver(nums,target,index+1,total+nums[index]);
        int negetive=solver(nums,target,index+1,total-nums[index]);
        return dp[{index,total}]=positive+negetive;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        //memset(dp,-1,sizeof(dp));
        return solver(nums,target,0,0);
    }
};