class Solution {
public:
    int dp[201][201];
    int solver(vector<vector<int>>&dungeon,int i=0,int j=0){
        int m=dungeon.size(),n=dungeon[0].size();
        if(i==m-1 and j==n-1){
            return dungeon[i][j]<=0 ? -dungeon[i][j]+1 : 1;
        }
        if(i==m or j==n){
            return 1e9;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int right=solver(dungeon,i,j+1);
        int down=solver(dungeon,i+1,j);

        int minhealth=min(right,down)-dungeon[i][j];

        return dp[i][j]=minhealth<=0 ? 1 : minhealth;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp,-1,sizeof dp);
        return solver(dungeon);
    }
};