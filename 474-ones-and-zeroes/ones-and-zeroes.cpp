class Solution {
public:
    int dp[601][101][101]={};
    pair<int,int> getcount(vector<string>&strs,int i){
        int zero=0,one=0;
        for(auto j : strs[i]){
            if(j=='1')one++;
            else zero++;
        }
        return {zero,one};
    }
    int solver(vector<string>& strs,int m,int n,int i){
        if(i>=strs.size() or(m==0 and n==0)){
            return 0;
        }
        pair<int,int> mn=getcount(strs,i);
        if(mn.first>m or mn.second>n){
            return solver(strs,m,n,i+1);
        }
        if(dp[i][m][n]!=-1)return dp[i][m][n];
        int include=1+solver(strs,m-mn.first,n-mn.second,i+1);
        int exclude=solver(strs,m,n,i+1);

        return dp[i][m][n]=max(include,exclude);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solver(strs,m,n,0);
    }
};