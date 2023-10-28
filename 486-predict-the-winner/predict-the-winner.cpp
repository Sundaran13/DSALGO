class Solution {
public:
    int dp[21][21][2];
    int solver(vector<int>&nums,int i,int j,bool player){
        if(i>j)return -1;
        if(i==j)return nums[i];
        if(dp[i][j][player]!=-1)return dp[i][j][player];
        if(player){
            return dp[i][j][player]=max(nums[i]+solver(nums,i+1,j,!player),nums[j]+solver(nums,i,j-1,!player));
        }
        else{
            return dp[i][j][player]=min(-nums[i]+solver(nums,i+1,j,!player),-nums[j]+solver(nums,i,j-1,!player));
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        if(solver(nums,0,nums.size()-1,true)>=0){
            return true;
        }
        else{
            return false;
        }
    }
};