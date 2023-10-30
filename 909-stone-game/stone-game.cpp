class Solution {
public:
    int dp[501][501];
    int solver(vector<int>&piles,int s,int e){
        if(s>=e){
            return 0;
        }
        if(dp[s][e]!=-1)return dp[s][e];
        int take=max(piles[s]+solver(piles,s+1,e),piles[e]+solver(piles,s,e-1));
        int nottake=min(-piles[s]+solver(piles,s+1,e),-piles[e]+solver(piles,s,e-1));
        return dp[s][e]=take+nottake;
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        if(solver(piles,0,piles.size()-1)>=0){
            return true;
        }
        else{
            return false;
        }
    }
};