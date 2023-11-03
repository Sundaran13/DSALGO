class Solution {
public:
    int vec[13];
    int n;
    int m;
    int dp[13][1<<13];
    int solver(int i,vector<vector<int>>&cost,int mask){
        if(i==n){
            int take=0;
            for(int i=0;i<m;i++){
                if((mask&(1<<i))==0){
                    take+=vec[i];
                }
            }
            return take;
        }
        if(dp[i][mask]!=-1)return dp[i][mask];
        int ans=INT_MAX;
        for(int j=0;j<m;j++){
            ans=min(ans,cost[i][j]+solver(i+1,cost,mask|(1<<j)));
        }
        return dp[i][mask]=ans;
    }
    int connectTwoGroups(vector<vector<int>>& cost) {
        n=cost.size();
        m=cost[0].size();
        for(int i=0;i<m;i++){
            vec[i]=500;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vec[j]=min(vec[j],cost[i][j]);
            }
        }
        memset(dp,-1,sizeof dp);
        return solver(0,cost,0);
    }
};