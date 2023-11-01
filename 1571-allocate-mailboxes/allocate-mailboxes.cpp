class Solution {
public:
    int costs[100][100];
    int dp[100][100];
    const int INF=100*10000;
    int solver(vector<int>&houses,int n,int k,int i){
        if(i==n and k==0){
            return 0;
        }
        if(i==n or k==0){
            return INF;
        }
        if(dp[k][i]!=-1)return dp[k][i];
        int ans=INF;
        for(int j=i;j<n;j++){
            ans=min(ans,costs[i][j]+solver(houses,n,k-1,j+1));
        }
        return dp[k][i]=ans;
    }
    int minDistance(vector<int>& houses, int k) {
        int n=houses.size();
        sort(houses.begin(),houses.end());
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int mid=(houses[(i+j)/2]);
                for(int k=i;k<=j;k++){
                    costs[i][j]+=abs(mid-houses[k]);
                }
            }
        }
        return solver(houses,n,k,0);
    }
};