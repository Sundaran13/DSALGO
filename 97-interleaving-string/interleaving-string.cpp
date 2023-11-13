class Solution {
public:
    
    bool solver(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<int>>&dp){
        if(i<0 and j<0 and k<0){
            return true;
        }
        if(i>=0 and j>=0 and dp[i][j]!=-1)return dp[i][j];
        if(i>=0 and s1[i]==s3[k] and j>=0 and s2[j]==s3[k]){
            return solver(s1,s2,s3,i-1,j,k-1,dp) or solver(s1,s2,s3,i,j-1,k-1,dp);
        }
        else if(i>=0 and s1[i]==s3[k]){
            return solver(s1,s2,s3,i-1,j,k-1,dp);
        }
        else if(j>=0 and s2[j]==s3[k]){
            return solver(s1,s2,s3,i,j-1,k-1,dp);
        }
        else{
            return false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        int l=s1.size(),m=s2.size(),n=s3.size();
        vector<vector<int>>dp(l+1,vector<int>(m+1,-1));
        if(n!=l+m){
            return false;
        }
        return solver(s1,s2,s3,l-1,m-1,n-1,dp);
    }
};