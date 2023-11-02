class Solution {
public:
    int n;
    int dp[4097][22][13];
    int solver(int node,int limit,int mask,vector<vector<int>>&graph){
        if(mask==(1<<n)-1){
            return 0;
        }
        if(limit==0)return 1e9;
        if(dp[mask][limit][node]!=-1)return dp[mask][limit][node];
        int ans=1e9;
        for(int adj:graph[node]){
            ans=min(ans,1+solver(adj,limit-1,mask|(1<<adj),graph));
        }
        return dp[mask][limit][node]=ans;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        n=graph.size();
        int ans=1e9;
        for(int i=0;i<n;i++){
            memset(dp,-1,sizeof dp);
            ans=min(ans,solver(i,21,1<<i,graph));
        }
        return ans;
    }
};