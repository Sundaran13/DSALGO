class Solution {
public:
    int minInsertions(string s) {
        string temp=s;
        reverse(temp.begin(),temp.end());
        int n=s.size(), m=s.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 or j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==temp[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return s.size()-dp[n][m];
    }
};