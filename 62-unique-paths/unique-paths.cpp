class Solution {
public:
    int dp[101][101];
    int solver(int row,int col,int m,int n){
        if(row==m-1 and col==n-1){
            return 1;
        }
        if(row>=m or col>=n){
            return 0;
        }
        if(dp[row][col]!=-1)return dp[row][col];
        return dp[row][col]=solver(row+1,col,m,n)+solver(row,col+1,m,n);
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof dp);
        return solver(0,0,m,n);
    }
};