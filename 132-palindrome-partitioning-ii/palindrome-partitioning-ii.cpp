class Solution {
public:
   // int dp[201][201];
    bool ispalin(string&s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    int solver(string &s,int start,int end,vector<int>&dp){
        if(start>=end or ispalin(s,start,end)){
            return 0;
        }
        if(dp[start]!=-1)return dp[start];
        int ans=INT_MAX;
        for(int k=start;k<end;k++){
            if(ispalin(s,start,k)){
                int temp=solver(s,k+1,end,dp)+1;
                ans=min(ans,temp);
            }
        }
        return dp[start]=ans;
    }
    int minCut(string s) {
        int n=s.size();
        //memset(dp,-1,sizeof dp);
        vector<int> dp(n+1,-1);
        return solver(s,0,s.length()-1,dp);
    }
};