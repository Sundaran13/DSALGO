class Solution {
public:
    int dp[55][55];
    int solver(vector<int>& values,int i,int k){
        if(k-i<=1)return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        int take=INT_MAX;
        for(int j=i+1;j<k;j++){
            take=min(take,values[i]*values[j]*values[k]+solver(values,i,j)+solver(values,j,k));
        }
        return dp[i][k]=take;
    }
    int minScoreTriangulation(vector<int>& values) {
        memset(dp,-1,sizeof dp);
        return solver(values,0,values.size()-1);
    }
};