class Solution {
public: 
   // int dp[4004][4004];
    bool solver(string &s,string&p,int i,int j,vector<vector<int>>&dp){
        if(i<0 and j<0){
            return true;
        }
        if(i>=0 and j<0){
            return false;
        }
        if(i<0 and j>=0){
            for(int k=0;k<=j;k++){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }
         if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==p[j] or p[j]=='?'){
            return dp[i][j]=solver(s,p,i-1,j-1,dp);
        }
        else if(p[j]=='*'){
            return dp[i][j]=solver(s,p,i-1,j,dp) or solver(s,p,i,j-1,dp);
        }
        else{
            return false;
        }
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length(),vector<int>(p.length(),-1));
        //memset(dp,-1,sizeof dp);
        return solver(s,p,s.size()-1,p.size()-1,dp);
    }
};