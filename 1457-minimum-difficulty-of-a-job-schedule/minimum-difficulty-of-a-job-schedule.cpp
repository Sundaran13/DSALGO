#define INF 10000000
class Solution {
public:
    int n;
    int dp[305][15];
    int solver(int i,int d,vector<int>&jd){
        if(i==n and d==0)return 0;
        if(i==n or d==0 or n-i<d)return INF;
        if(dp[i][d]!=-1)return dp[i][d];
        int ans=INF;
        int max_ele=-INF;
        for(int j=i;j<n;j++){
            max_ele=max(max_ele,jd[j]);
            ans=min(ans,max_ele+solver(j+1,d-1,jd));
        }
        return dp[i][d]=ans;
    }
    int minDifficulty(vector<int>& jd, int d) {
        n=jd.size();
        memset(dp,-1,sizeof(dp));
        if(n<d)return -1;
        return solver(0,d,jd);
    }
};