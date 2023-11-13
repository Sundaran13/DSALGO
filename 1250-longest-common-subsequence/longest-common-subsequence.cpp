class Solution {
public:
    // int maxi=0;
    // //int dp[1001][1001];
    // int solver(string &text1,string &text2,int i,int j){
    //     if(i>=text1.size() or j>=text2.size()){
               
    //         return 0;
    //     }

    //     if(dp[i][j]!=-1)return dp[i][j];
    //     ///i//nt ans=0;
    //     //string ans="";
    //     if(text1[i]==text2[j]){
    //         return 1+solver(text1,text2,i+1,j+1);
    //     }        
    //     else{
    //         return dp[i][j]=max(solver(text1,text2,i+1,j),solver(text1,text2,i,j+1));
    //     }
    // }
    int longestCommonSubsequence(string text1, string text2) {
        //memset(dp,-1,sizeof dp);
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=0;i<=text1.size();i++)dp[i][0]=0;
        for(int j=0;j<=text2.size();j++)dp[0][j]=0;
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                    if(text1[i-1]==text2[j-1]){
                        dp[i][j]=1+dp[i-1][j-1];
                    }        
                    else{
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        return dp[text1.size()][text2.size()];
        //return maxi;
    }
};