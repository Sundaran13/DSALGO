class Solution {
public:
    int dp[1001];
    vector<int> ans;
    void solver(vector<int>&nums,int i,int prev,vector<int>temp){
        if(i>=nums.size()){
            if(temp.size()>ans.size()){
                ans=temp;
            }
            return;
        }
        if(nums[i]%prev==0 and (int)temp.size()>dp[i]){
            dp[i]=temp.size();
            temp.push_back(nums[i]);
            solver(nums,i+1,nums[i],temp);
            temp.pop_back();
        }
        solver(nums,i+1,prev,temp);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        memset(dp,-1,sizeof dp);
        solver(nums,0,1,temp);
        return ans;
    }
};