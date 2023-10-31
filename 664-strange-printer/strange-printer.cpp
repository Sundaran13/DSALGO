class Solution {
public:
    int dp[101][101];
    int solver(int l,int r,string &s){
        if(l==r){
            return 1;
        }
        if(dp[l][r]!=-1)return dp[l][r];
        int ans=INT_MAX;
        for(int i=l;i<r;i++){
            ans=min(ans,solver(l,i,s)+solver(i+1,r,s));
        }
        return dp[l][r]=s[l]==s[r]?ans-1:ans;
    }
    int strangePrinter(string s) {
        memset(dp,-1,sizeof dp);
        int n=s.size()-1;
        return solver(0,n,s);
    }
};