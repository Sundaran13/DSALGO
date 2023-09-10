class Solution {
public:
    int solver(int n,vector<int>&dp){
        if(n<4){
            return n;
        }
        if(dp[n]!=-1)return dp[n];
        int ans=n;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+solver(n-i*i,dp));
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solver(n,dp);
    }
};