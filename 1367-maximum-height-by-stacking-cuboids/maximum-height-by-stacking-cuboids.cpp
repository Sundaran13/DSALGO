class Solution {
public:
    int dp[2501][2501];
    bool check(int i,int prev,vector<vector<int>>&a){
        if(a[i][0]>=a[prev][0] and a[i][1]>=a[prev][1] and a[i][2]>=a[prev][2]){
            return true;
        }
        else{
            return false;
        }
    }
    int solver(vector<vector<int>>&a,int prev,int i){
        if(i==a.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int take=0,not_take=0;
        if(prev==-1 or check(i,prev,a)){
            take=a[i][2]+solver(a,i,i+1);
        }
        not_take=solver(a,prev,i+1);
        return dp[i][prev+1]=max(take,not_take);
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &it: cuboids){
            sort(it.begin(),it.end());
        }
        sort(cuboids.begin(),cuboids.end());
        memset(dp,-1,sizeof dp);
        return solver(cuboids,-1,0);
    }
};