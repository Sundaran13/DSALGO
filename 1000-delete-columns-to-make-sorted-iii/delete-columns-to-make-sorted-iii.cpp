class Solution {
public:
    int dp[101][101];
    int solver(vector<string>&strs,int curr,int prev){
        if(curr==strs[0].size()){
            return 0;
        }
        if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
        int ans=0;
        bool flag=1;
        ans=solver(strs,curr+1,prev);
        if(prev!=-1){
            for(int i=0;i<strs.size();i++){
                if(strs[i][curr]<strs[i][prev]){
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1){
            ans=max(ans,1+solver(strs,curr+1,curr));
        }
        return dp[curr][prev+1]=ans;
    }
    int minDeletionSize(vector<string>& strs) {
        memset(dp,-1,sizeof dp);
        return strs[0].length()-solver(strs,0,-1);
    }
};