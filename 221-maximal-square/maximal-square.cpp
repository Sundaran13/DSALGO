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
        memset(dp,-1,sizeof dp);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                
                ans=max(ans,solver(matrix,i,j));
            }
        }
        return ans*ans;
    }
};