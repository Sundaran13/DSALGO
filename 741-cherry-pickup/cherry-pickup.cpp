class Solution {
public:
    int n=0;
    int dp[51][51][51][51];
    int solver(vector<vector<int>>&grid,int r1,int c1,int r2,int c2){
        if(r1>=n or c1>=n or r2>=n or c2>=n or grid[r1][c1]==-1 or grid[r2][c2]==-1){
            return INT_MIN;
        }
        if(r1==n-1 and c1==n-1){
            return grid[r1][c1];
        }
        if(r2==n-1 and c2==n-1){
            return grid[r2][c2];
        }
        if(dp[r1][c1][r2][c2]!=-1)return dp[r1][c1][r2][c2];
        int ans=0;
        if(r1==r2 and c1==c2){
            ans=grid[r1][c1];
        }
        else{
            ans = grid[r1][c1]+ grid[r2][c2];
        }
        ans+=max({solver(grid,r1+1,c1,r2+1,c2),solver(grid,r1+1,c1,r2,c2+1),solver(grid,r1,c1+1,r2+1,c2),solver(grid,r1,c1+1,r2,c2+1)});
        return dp[r1][c1][r2][c2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        memset(dp,-1,sizeof dp);
        return max(0,solver(grid,0,0,0,0));
    }
};