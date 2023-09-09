class Solution {
public:
    int maxprofit_func(vector<int>& prices,int i,bool buy,int cnt,vector<vector<vector<int>>>&dp){
        if(i>=prices.size() or cnt>=2){
            return 0;
        }
        if(dp[i][buy][cnt]!=-1)return dp[i][buy][cnt];
        if(buy){
            return dp[i][buy][cnt]=max(-prices[i]+maxprofit_func(prices,i+1,!buy,cnt,dp),maxprofit_func(prices,i+1,buy,cnt,dp));
        }
        else{
            return dp[i][buy][cnt]=max(prices[i]+maxprofit_func(prices,i+1,!buy,cnt+1,dp),maxprofit_func(prices,i+1,buy,cnt,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        int n=prices.size();
        return maxprofit_func(prices,0,1,0,dp);
    }
};