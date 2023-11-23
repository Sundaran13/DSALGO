class Solution {
public:
int m,n;
    int dp[301][301];
    int solver(vector<vector<int>>&matrix,int i,int j){
        if(i>=m or j>=n or matrix[i][j]==0){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=1+min({solver(matrix,i+1,j),solver(matrix,i,j+1),solver(matrix,i+1,j+1)});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        memset(dp,-1,sizeof dp);
        m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                   ans+=solver(matrix,i,j);
                }
            }
        }
        return ans;
    }
};