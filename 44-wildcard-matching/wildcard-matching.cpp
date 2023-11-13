class Solution {
public: 
   int dp[2001][2001];
    bool solver(string &s,string&p,int i,int j){
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
            return dp[i][j]=solver(s,p,i-1,j-1);
        }
        else if(p[j]=='*'){
            return dp[i][j]=solver(s,p,i-1,j) or solver(s,p,i,j-1);
        }
        else{
            return dp[i][j]=false;
        }
    }
    bool isMatch(string s, string p) {
        //vector<vector<int>> dp(s.length(),vector<int>(p.length(),-1));
        memset(dp,-1,sizeof dp);
        return solver(s,p,s.size()-1,p.size()-1);
    }
};