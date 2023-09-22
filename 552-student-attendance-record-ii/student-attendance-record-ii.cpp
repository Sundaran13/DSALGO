class Solution {
public:
    long long int mod=1e9+7;
    long long int dp[100001][2][3];
    int solver(int n,int absent,int late){
        if(late>=3 or absent>=2){
            return 0;
        }
        if(n==0)return 1;
        if(dp[n][absent][late]!=-1)return dp[n][absent][late];
        int p=solver(n-1,absent,0);
        int a=solver(n-1,absent+1,0);
        int l=solver(n-1,absent,late+1);

        return dp[n][absent][late]=(p%mod+a%mod+l%mod)%mod;
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return solver(n,0,0);
    }
};