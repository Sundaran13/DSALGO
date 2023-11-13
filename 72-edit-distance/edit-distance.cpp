class Solution {
public:
    long long solver(string word1,string word2,int i,int j,vector<vector<int>>&dp){
        if(i==0)return j;
        if(j==0)return i;
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i-1]==word2[j-1]){
            return dp[i][j]=solver(word1,word2,i-1,j-1,dp);
        }
        else{
            int insert=solver(word1,word2,i,j-1,dp);
            int delete1=solver(word1,word2,i-1,j,dp);
            int replace=solver(word1,word2,i-1,j-1,dp);
            return dp[i][j]=1+min({insert,delete1,replace});
        }
    }
    int minDistance(string word1, string word2) {
        //memset(dp,-1,sizeof dp);
        int m=word1.size(),n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solver(word1,word2,word1.length(),word2.length(),dp);
    }
};