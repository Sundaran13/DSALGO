class Solution {
public:
    //int ans;
    int dp[501][501][4];
    vector<vector<int>> vec={{0,-1},{0,1},{1,0},{-1,0}};
    int solver(vector<vector<int>>&grid,int i,int j,int k){
        int n=grid.size();
        int ni=i+vec[k][0];
        int nj=j+vec[k][1];

        if(dp[i][j][k]!=-1)return dp[i][j][k];
        if(ni<0 or nj<0 or ni>=n or nj>=n or grid[ni][nj]==0)return 0;

        return dp[i][j][k]=1+solver(grid,ni,nj,k);
    }
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int ans=0;
        vector<vector<int>> grid(n,vector<int>(n,1));
        memset(dp,-1,sizeof dp);
        for(int i=0;i<mines.size();i++){
            grid[mines[i][0]][mines[i][1]]=0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans=max(ans,1+min({solver(grid,i,j,0),solver(grid,i,j,1),solver(grid,i,j,2),solver(grid,i,j,3)}));
                }
            }
        }
        return ans;
    }
};