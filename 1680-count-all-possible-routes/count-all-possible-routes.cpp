class Solution {
public:
    const int MOD =1000000007;
    //long long dp[101][201];
    int solver(const vector<int>&locations,int start,int finish,int fuel,vector<vector<int>>&dp){
        if(fuel<0)return 0;
        if(dp[start][fuel]!=-1)return dp[start][fuel];
        int total=start==finish?1:0;
        for(int nextcity=0;nextcity<locations.size();nextcity++){
            if(nextcity!=start and fuel>=(abs(locations[nextcity]-locations[start]))){
                total+=(solver(locations,nextcity,finish,fuel-abs(locations[nextcity]-locations[start]),dp))%MOD;
            }
        }
        return dp[start][fuel]=total%MOD;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        //memset(dp,-1,sizeof(dp));

        vector<vector<int>> dp(n, vector<int>(fuel + 1, 0));
        for(int f=0;f<=fuel;f++){
            dp[finish][f]=1;
        }
        for(int f=0;f<=fuel;f++){
            for(int start=0;start<n;start++){
                for(int nextcity=0;nextcity<n;nextcity++){
                    if(nextcity!=start and f>=(abs(locations[nextcity]-locations[start]))){
                        dp[start][f]=(dp[start][f]+dp[nextcity][f-abs(locations[nextcity]-locations[start])])%MOD;
                    }
                }
            }
        }
        return dp[start][fuel];
    }
};