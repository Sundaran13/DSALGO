class Solution {
public:
    int dp[301][301];
    int solver(vector<int>&cleaned,int start,int end){
        if(start>end){
            return 0;
        }
        if(start==end){
            return dp[start][end]=cleaned[start-1]*cleaned[start]*cleaned[start+1];
        }
        if(dp[start][end]!=-1)return dp[start][end];
        int ans=INT_MIN;
        for(int i=start;i<=end;i++){
            ans=max(ans,cleaned[start-1]*cleaned[i]*cleaned[end+1]+solver(cleaned,start,i-1)+solver(cleaned,i+1,end));
        }
        return dp[start][end]=ans;
    }
    int maxCoins(vector<int>& nums) {
        vector<int> cleaned={1};
        for(auto &it:nums){
            if(it)cleaned.push_back(it);
        }
        memset(dp,-1,sizeof dp);
        cleaned.push_back(1);
        int n=cleaned.size()-2;
        return solver(cleaned,1,n);
    }
};