class Solution {
public:
    int dp[301][301];
    int solver(vector<vector<char>>&matrix,int i,int j){
        if(i>=matrix.size() or j>=matrix[0].size() or matrix[i][j]=='0'){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=min({solver(matrix,i+1,j),solver(matrix,i,j+1),solver(matrix,i+1,j+1)})+1;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;
        memset(dp,0,sizeof dp);
        for(int i=matrix.size()-1;i>=0;i--){
            for(int j=matrix[0].size()-1;j>=0;j--){
                if(j==matrix[0].size()-1){
                    dp[i][j]=matrix[i][j]=='0'? 0 : 1;
                }
                else if(i==matrix.size()-1){
                    dp[i][j]=matrix[i][j]=='0'? 0 : 1;
                }
                else if(matrix[i][j]=='0'){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]})+1;
                }
                ans=max(ans,dp[i][j]);                
            }
        }
        return ans*ans;
    }
};