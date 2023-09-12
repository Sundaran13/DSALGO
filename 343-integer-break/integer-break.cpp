class Solution {
public:
    int solver(int n,vector<int>&dp){
        if(n==2)return 1;
        if(n==3)return 2;
        if(dp[n]!=-1)return dp[n];
        int maxi=0;
        for(int i=1;i<n;i++){
            maxi=max({maxi,i*solver(n-i,dp),(n-i)*i});
        }
        return dp[n]=maxi;
    }
    int integerBreak(int n) {
        if(n==2){
            return 1;
        }
        if(n==3){
            return 2;
        }
        vector<int> dp(n+1,0);
        dp[2]=1;dp[3]=2;
        for(int i=2;i<=n;i++){
            int maxi=0;
            for(int j=1;j<i;j++){
                maxi=max({maxi,j*dp[i-j],(i-j)*j});
            }
            dp[i]=maxi;
            }
        return dp[n];
    }
};