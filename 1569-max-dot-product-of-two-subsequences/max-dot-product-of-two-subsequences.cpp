class Solution {
public:
    int dp[501][501];
    int solver(vector<int>&nums1,vector<int>&nums2,int i,int j){
        if(i>=nums1.size() or j>=nums2.size()){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int op1=solver(nums1,nums2,i+1,j);
        int op2=solver(nums1,nums2,i,j+1);
        int op3=solver(nums1,nums2,i+1,j+1)+nums1[i]*nums2[j];
        int op4=solver(nums1,nums2,i+1,j+1);

        return dp[i][j]=max({op1,op2,op3});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int ans;
        memset(dp,-1,sizeof dp);
        ans=solver(nums1,nums2,0,0);
        if(ans==0){
            int a=*max_element(nums1.begin(),nums1.end());
            int b=*min_element(nums1.begin(),nums1.end());

            int c=*max_element(nums2.begin(),nums2.end());
            int d=*min_element(nums2.begin(),nums2.end());

            return max(a*d, b*c);
        }
        return ans;
    }
};