class Solution {
public:
    int maxi=0;
    int dp[1001][1001];
    int solver(string &text1,string &text2,int i,int j){
        if(i>=text1.size() or j>=text2.size()){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        ///i//nt ans=0;
        if(text1[i]==text2[j]){
            return dp[i][j]=1+solver(text1,text2,i+1,j+1);
        }        
        else{
            return dp[i][j]=max(solver(text1,text2,i+1,j),solver(text1,text2,i,j+1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof dp);
        return solver(text1,text2,0,0);
        //return maxi;
    }
};