class Solution {
public:
    int solver(vector<vector<int>>&grid,int col,int row){
        if(row>=grid.size()){
            return col;
        }
        if(grid[row][col]==1){
            if(col+1>=grid[0].size() or grid[row][col+1]==-1)return -1;
            return solver(grid,col+1,row+1);
        }
        else{
            if(col-1<0 or grid[row][col-1]==1)return -1;
            return solver(grid,col-1,row+1);
        }
        
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<int> vec(grid[0].size());
        for(int i=0;i<n;i++){
            vec[i]=solver(grid,i,0);
        }
        return vec;
    }
};