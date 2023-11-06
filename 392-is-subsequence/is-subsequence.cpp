class Solution {
public:
    int dp[101][10001];
    int solver(string&s,string& t,int i,int j){
        if(i==0 or j==0){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i-1]==t[j-1]){
            return dp[i][j]=1+solver(s,t,i-1,j-1);
        }
        else{
            return dp[i][j]=solver(s,t,i,j-1);
        }
    }
    bool isSubsequence(string s, string t) {
        int m=s.size();
        int n=t.size();
        memset(dp,-1,sizeof dp);
        if(m>n){
            return false;
        }
        if(solver(s,t,m,n)==m){
            return true;
        }
        else{
            return false;
        }
    }
};