class Solution {
public:
    int dp[101][101];
    int solver(vector<vector<int>>&obstacleGrid,int i,int j,int m,int n){
        if(i<m and j<n and obstacleGrid[i][j]==1){
            return 0;
        }
        if(i==m-1 and j==n-1){
            return 1;
        }
        if(i>=m or j>=n){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=solver(obstacleGrid,i+1,j,m,n)+solver(obstacleGrid,i,j+1,m,n);
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        memset(dp,-1,sizeof dp);
        return solver(obstacleGrid,0,0,m,n);
    }
};