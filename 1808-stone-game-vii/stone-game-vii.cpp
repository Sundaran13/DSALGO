class Solution {
public:
    int dp[1001][1001];
    int solver(int left,int right,int sum,vector<int>&stones){
        if(left>=right or sum<=0){
            return 0;
        }
        if(dp[left][right]!=-1)return dp[left][right];
        int chose_front=sum-stones[left]-solver(left+1,right,sum-stones[left],stones);
        int chose_back=sum-stones[right]-solver(left,right-1,sum-stones[right],stones);

        return dp[left][right]=max(chose_front,chose_back);
    }
    int stoneGameVII(vector<int>& stones) {
        int sum=0;
        for(auto it:stones){
            sum+=it;
        }
        memset(dp,-1,sizeof dp);
        int n=stones.size();
        return solver(0,n-1,sum,stones);
    }
};