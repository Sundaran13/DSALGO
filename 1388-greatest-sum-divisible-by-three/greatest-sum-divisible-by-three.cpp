class Solution {
public:
    map<pair<int,int>,int> dp;
    int solver(vector<int>&nums,int i,int rem){
        if(i>=nums.size()){
            if(rem==0){
                return 0;
            }
            else{
                return INT_MIN;
            }
        }
        if(dp.find({i,rem})!=dp.end()){
            return dp[{i,rem}];
        }
        int pick,not_pick;
        pick=nums[i]+solver(nums,i+1,(nums[i]+rem)%3);
        not_pick=solver(nums,i+1,rem);
        return dp[{i,rem}]=max(pick,not_pick);        
    }
    int maxSumDivThree(vector<int>& nums) {
        return solver(nums,0,0);
    }
};