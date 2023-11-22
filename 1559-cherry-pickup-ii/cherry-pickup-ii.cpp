class Solution {
public:
    vector<int> dy={0,-1,1};
    int dp[71][71][71];
    int solver(vector<vector<int>>&grid,int i,int j,int l){
        if(i==grid.size()){
            return 0;
        }
        if( j<0 or l<0 or j>=grid[0].size() or l>=grid[0].size()){
            return INT_MIN;
        }        
        if(dp[i][j][l]!=-1)return dp[i][j][l];
        int total=0;
        for(int z=0;z<3;z++){
            for(int r=0;r<3;r++){
                total=max(total,solver(grid,i+1,j+dy[z],l+dy[r]));
            }
        }
        if(j==l){
            total+=grid[i][j];
        }
        else{
            total+=grid[i][j]+grid[i][l];
        }
        return dp[i][j][l]=total;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        if(!m)return 0;
        memset(dp,-1,sizeof dp);
        return solver(grid,0,0,grid[0].size()-1);
    }
};