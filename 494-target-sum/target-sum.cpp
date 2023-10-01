class Solution {
public:
    int solver(vector<int>&nums,int target,int index,int total){
        if(index>=nums.size()){
            if(total==target)return 1;
            else return 0;
        }
        int positive=solver(nums,target,index+1,total+nums[index]);
        int negetive=solver(nums,target,index+1,total-nums[index]);
        return positive+negetive;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solver(nums,target,0,0);
    }
};