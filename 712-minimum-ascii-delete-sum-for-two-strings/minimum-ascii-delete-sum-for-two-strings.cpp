class Solution {
public:
    int dp[1001][1001];
    int sum(string &s,int i){
        int sum1=0;
        for(;i<s.length();i++){
            sum1+=s[i];
        }
        return sum1;
    }
    int solver(string &s1,string &s2,int i,int j,int n,int m){
        if(i==n or j==m){
            if(i==n and j==m)return 0;
            return i==n?sum(s2,j):sum(s1,i);
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=solver(s1,s2,i+1,j+1,n,m);
        }
        else{
            return dp[i][j]=min(int(s1[i])+solver(s1,s2,i+1,j,n,m),int(s2[j])+solver(s1,s2,i,j+1,n,m));
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof dp);
        int n=s1.length(),m=s2.length();
        return solver(s1,s2,0,0,n,m);
    }
};