class Solution {
public:
    long long mod=1e9+7;
    long long solver(vector<vector<int>>&keypad,int i,int j,int n,vector<vector<vector<long long>>>&dp){
        if(i<0 or i>=4 or j<0 or j>=3 or (i==3 and j!=1)){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(dp[i][j][n]!=-1)return dp[i][j][n];
        long long a=(solver(keypad,i-2,j-1,n-1,dp)%mod+
                    solver(keypad,i-2,j+1,n-1,dp)%mod+
                    solver(keypad,i-1,j-2,n-1,dp)%mod+
                    solver(keypad,i-1,j+2,n-1,dp)%mod+
                    solver(keypad,i+2,j-1,n-1,dp)%mod+
                    solver(keypad,i+2,j+1,n-1,dp)%mod+
                    solver(keypad,i+1,j-2,n-1,dp)%mod+
                    solver(keypad,i+1,j+2,n-1,dp)%mod)%mod;
        return dp[i][j][n]=(int)a;
    }
    int knightDialer(int n) {
        vector<vector<int>> keypad={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        vector<vector<vector<long long>>> dp(4,vector<vector<long long>>(3,vector<long long>(n+1,-1)));
        int res=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                res=(res+solver(keypad,i,j,n,dp))%mod;
            }
        }
        return res;
    }
};