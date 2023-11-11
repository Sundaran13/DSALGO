class Solution {
public:
    int dp[1001][1001];
    int solver(string&s,int i,int j){
        if(j-i+1==1){
            return 1;
        }
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]=2+solver(s,i+1,j-1);
        }
        else{
            return dp[i][j]=max(solver(s,i+1,j),solver(s,i,j-1));
        }
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof dp);
        return solver(s,{},s.size()-1);
    }
};