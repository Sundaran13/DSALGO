class Solution {
public:
    int dp[1<<17][17];
    bool solver(vector<int>&nums,int target,int currsum,int vis,int k){
        if(k==1)return true;
        if(dp[vis][k]!=-1)return dp[vis][k];
        bool flg=false;
        if(currsum==target){
            return dp[vis][k]=solver(nums,target,0,vis,k-1);
        }
        for(int i=0;i<nums.size();i++){
            int mask=(1<<i);
            if((mask&vis)==0 and currsum+nums[i]<=target){
                int temp=vis;
                vis|=mask;
                flg=flg+solver(nums,target,currsum+nums[i],vis,k);
                vis=temp;
                }
        }
        return dp[vis][k]=flg;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s=accumulate(nums.begin(),nums.end(),0);
        if(nums.size()<k or s%k)return false;
        memset(dp,-1,sizeof dp);
        return solver(nums,s/k,0,0,k);
    }
};