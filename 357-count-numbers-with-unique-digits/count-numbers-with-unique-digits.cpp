class Solution {
public:
    int solver(int n,vector<int>&dp){
        if(n==0)return 1;
        if(dp[n]!=-1)return dp[n];
        int sum=9;
        for(int i=0;i<n-1;i++){
            sum*=(9-i);
        }
        return dp[n]=sum+solver(n-1,dp);
    }
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n+1,-1);
       return solver(n,dp);
    }
};