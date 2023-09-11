class Solution {
public:
    int solver(int n,vector<int>&dp){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1)return dp[n];
        return dp[n]=n%2+solver(n/2,dp);
    }
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        vector<long long int> dp(n+1,0);
        for(long long int i=0;i<=n;i++){
            dp[i]=i%2+dp[i/2];
            res[i]=dp[i];            
        }
        return res;
    }
};