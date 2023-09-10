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
        vector<int> dp(n+1);

        for(int i=1;i<=n;i++){
            if(i<4){
                dp[i]=i;continue;
            }
            int ans=i;
            for(int j=1;j*j<=i;j++){
                ans=min(ans,1+dp[i-j*j]);
            }
            dp[i]=ans;
            }
        return dp[n];
    }
};