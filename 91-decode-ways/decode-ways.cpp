class Solution {
public:
    int solver(const string &s,int i,vector<int>&dp){
        if(i==s.size())return 1;
        if(dp[i]!=-1)return dp[i];
        int ans=0;
        if(s[i]!='0'){
            ans+=solver(s,i+1,dp);
        }
        if(i+1<s.size() and (s[i]=='1' or s[i]=='2' and s[i+1]<='6')){
            ans+=solver(s,i+2,dp);
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        vector<int> dp(s.length(),-1);
        return solver(s,0,dp);
    }
};