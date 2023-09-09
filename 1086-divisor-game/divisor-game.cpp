class Solution {
public:
    bool solver(int n,vector<int>&dp){
        if(n==1){
            return false;
        }
        if(dp[n]!=-1)return dp[n];
        for(int i=1;i<n;i++){
            if(n%i==0 and !solver(n-i,dp)){
                return dp[n]=true;
            }
        }
        return dp[n]=false;
    }
    bool divisorGame(int n) {
        vector<int> dp(n+1,0);
        dp[1]=false;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                if(i%j==0 and !dp[i-j]){
                    dp[i]=true;
                }
            }          
        }
        return dp[n];
    }
};