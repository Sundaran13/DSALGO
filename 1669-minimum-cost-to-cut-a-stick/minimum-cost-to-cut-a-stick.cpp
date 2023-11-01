class Solution {
public:
    long long int dp[101][101];
    int solver(int start,int end,vector<int>&cuts,int cuts_start,int cuts_end){
        if(cuts_start>cuts_end){
            return 0;
        }
        if(dp[cuts_start][cuts_end]!=-1)return dp[cuts_start][cuts_end];
        int ans=INT_MAX;
        for(int i=cuts_start;i<=cuts_end;i++){
            ans=min(ans,end-start+solver(start,cuts[i],cuts,cuts_start,i-1)+solver(cuts[i],end,cuts,i+1,cuts_end));
        }
        return dp[cuts_start][cuts_end]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        memset(dp,-1,sizeof dp);
        return solver(0,n,cuts,0,cuts.size()-1);
    }
};