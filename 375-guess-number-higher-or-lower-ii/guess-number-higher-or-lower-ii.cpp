class Solution {
public:
    int dp[201][201];
    int solver(int n,int l,int r){
        if(l>=r){
            return 0;
        }
        if(dp[l][r]!=-1)return dp[l][r];
        int res=INT_MAX;
        for(int i=l;i<=r;i++){
            res=min(res,max(i+solver(n,l,i-1),i+solver(n,i+1,r)));
        }
        return dp[l][r]=res;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return solver(n,1,n);
    }
};