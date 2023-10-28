class Solution {
public:
    int dp[1001][1001];
    bool solver(string s,int i,int j){
        if(i==j){
            return true;
        }
        if(s[i]!=s[j]){
            return false;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(i<=j)
            return dp[i][j]=solver(s,i+1,j-1);
        return dp[i][j]=true;
    }
    int countSubstrings(string s) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<s.size();i++){
            for(int j=s.size()-1;j>=i;j--){
                ans+=solver(s,i,j);
            }
        }
        return ans;
    }
};