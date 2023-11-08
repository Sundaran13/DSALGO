class Solution {
public:
    int dp[101][101],cp[101][101];
    const int INF=1e2+5;
    int cost(string &s,int i,int j){
        if(i>=j)return 0;
        if(cp[i][j]!=-1)return cp[i][j];
        return cp[i][j]=(s[i]!=s[j])+cost(s,i+1,j-1);
    }
    int solver(string &s,int i,int k){
        if(k==0)return cost(s,i,s.size()-1);
        if(i==s.size())return INF;
        if(dp[i][k]!=-1)return dp[i][k];
        int ans=INF;
        for(int start=i;start<s.size()-1;start++){
            ans=min(ans,cost(s,i,start)+solver(s,start+1,k-1));
        }
        return dp[i][k]=ans;
    }
    int palindromePartition(string s, int k) {
        memset(dp,-1,sizeof dp);
        memset(cp,-1,sizeof cp);
        return solver(s,0,k-1);
    }
};