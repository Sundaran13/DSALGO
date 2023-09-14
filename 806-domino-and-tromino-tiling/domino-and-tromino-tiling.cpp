
class Solution {
public:
    const int MOD=1e9+7;
    long solver(int i,int n,bool prev_gap,vector<vector<int>>&dp){
        if(i>n){
            return 0;
        }
        if(i==n) return !prev_gap;
        if(dp[i][prev_gap]!=-1)return dp[i][prev_gap];
        if(prev_gap==false){
            return dp[i][prev_gap]=(solver(i+1,n,prev_gap,dp)%MOD + solver(i+2,n,prev_gap,dp)%MOD + solver(i+2,n,!prev_gap,dp)%MOD + solver(i+2,n,!prev_gap,dp)%MOD)%MOD;            
        }
        else{
            return dp[i][prev_gap]=(solver(i+1,n,!prev_gap,dp)%MOD + solver(i+1,n,prev_gap,dp)%MOD)%MOD;           
            
        }
    }
    int numTilings(int n) {
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solver(0,n,false,dp);
    }
};