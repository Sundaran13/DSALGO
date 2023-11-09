class Solution {
public:
    vector<pair<int,int>> res={{100,0},{75,25},{50,50},{25,75}};
    double ans(int A,int B,vector<vector<double>>&dp){
        if(A<=0 && B<=0) return 0.5;
        if(A<=0) return 1.0;
        if(B<=0) return 0.0;
        if(dp[A][B]!=-1)return dp[A][B];
        double ans1=0.0;
        for(auto it: res){
            ans1+= ans(A-it.first,B-it.second,dp);
        }
        return dp[A][B]=ans1*=0.25;
    }
    double soupServings(int n) {
        if(n>=5000){
            return 1.0;
        }
        vector<vector<double>> dp(n+1,vector<double>(n+1,-1));
        return ans(n,n,dp);
    }
};