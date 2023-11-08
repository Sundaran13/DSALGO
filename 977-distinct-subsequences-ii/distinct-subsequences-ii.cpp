class Solution {
public:
    int mod=1e9+7;
    unordered_map<int,int> dp;
     set<string> res;
    int solver(string &s,int i){
        if(i>=s.size()){
            return 0;
        }
        if(dp.find(i)!=dp.end())return dp[i];
        vector<int> vis(26,0);
        int ans=0;
        for(int j=i;j<s.size();j++){
            if(vis[s[j]-'a'])continue;
            vis[s[j]-'a']=1;
            ans=(ans+1+solver(s,j+1)%mod)%mod;
        }
        return dp[i]=ans;
    }
    int distinctSubseqII(string s) {
        return solver(s,0);
    }
};