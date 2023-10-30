class Solution {
public:
    int dp[31][10001];
    int solver(vector<int>&stones,int i,int val,int n){
        if(i==n){
            if(val<0){
                return 1e9;
            }
            return 0;
        }
        if(dp[i][val+3000]!=-1)return dp[i][val+3000];
        int positive=+stones[i]+solver(stones,i+1,val+stones[i],n);
        int negative=-stones[i]+solver(stones,i+1,val-stones[i],n);
        return dp[i][val+3000]=min(positive,negative);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        memset(dp,-1,sizeof dp);
        return solver(stones,0,0,n);
    }
};