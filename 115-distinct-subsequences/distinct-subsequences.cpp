class Solution {
public:
    int dp[1000][1000];
    int solver(string &s,string& t,int idxs,int idxt,int n,int m){
        if(idxt==m)return 1;
        if(idxs==n)return 0;
        if(dp[idxs][idxt]!=-1)return dp[idxs][idxt];
        if(s[idxs]==t[idxt]){
            return dp[idxs][idxt]=solver(s,t,idxs+1,idxt+1,n,m)+solver(s,t,idxs+1,idxt,n,m);
        }
        return dp[idxs][idxt]=solver(s,t,idxs+1,idxt,n,m);
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof dp);
        return solver(s,t,0,0,s.size(),t.size());
    }
};