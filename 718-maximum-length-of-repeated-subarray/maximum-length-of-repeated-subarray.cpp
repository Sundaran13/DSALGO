class Solution {
public:
    int dp[1000][1000];
    int max1=0;
    int solver(vector<int>&nums1,vector<int>&nums2,int i,int j){
        if(i>=nums1.size() or j>=nums2.size()){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        else{
            int currmax=0;
            if(nums1[i]==nums2[j]){
                currmax=solver(nums1,nums2,i+1,j+1)+1;
                max1=max(max1,currmax);
            }
            solver(nums1,nums2,i+1,j);
            solver(nums1,nums2,i,j+1);
             return dp[i][j]=currmax;
        }
 

       

    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof dp);
        solver(nums1,nums2,0,0);
        return max1;
    }
};