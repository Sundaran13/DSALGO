struct comparator{
    bool operator()(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
};
class Solution {
public:
    int solver(vector<vector<int>>&pairs,int i,int prev_ele,vector<vector<int>>&dp){
        if(i>=pairs.size()){
            return 0;
        }     
        if(dp[i][prev_ele]!=-1)return dp[i][prev_ele];
        int keep=0,skip=0;
        if(pairs[i][0]+1001>prev_ele){
            keep=1+solver(pairs,i+1,pairs[i][1]+1001,dp);
            
        }
        skip=solver(pairs,i+1,prev_ele,dp);
        return dp[i][prev_ele]=max(keep,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comparator());
        vector<vector<int>> dp(pairs.size(),vector<int>(2003,-1));
        return solver(pairs,0,0,dp);
        //return pairs[1][0];
    }
};