class Solution {
public:
    long MOD=1000000007;
    int n=0;
    int take=(1<<n);
    int dp[41][40*40];
    int solver(int hats,int person,unordered_map<int,vector<int>>&mpp,int n){
        if(person==(1<<n)-1){
            return 1;
        }
        if(hats>40){
            return 0;
        }
        if(dp[hats][person]!=-1)return dp[hats][person];
        int res=solver(hats+1,person,mpp,n);
        for(auto it:mpp[hats]){
            if((person&(1<<it))==0){
                res=(res+solver(hats+1,person|(1<<it),mpp,n))%MOD;
            }
        }
        return dp[hats][person]=res%MOD;
    }
    int numberWays(vector<vector<int>>& hats) {
        n=hats.size();
        unordered_map<int,vector<int>>mpp;
        for(int person=0;person<n;person++){
            for(auto it:hats[person]){
                mpp[it].push_back(person);
            }
        }
        memset(dp,-1,sizeof dp);
        return (solver(1,0,mpp,n))%MOD;
    }
};