//#define MOD 1e9+7
class Solution {
public:
    const int MOD=1e9+7;
    long long solver(long long n){
        if(n==1){
            return 1;
        }
        return ((2*n-1)*n*solver(n-1))%MOD;
    }
    int countOrders(int n) {
        vector<long long int> dp(n+1);
        dp[1]=1;
       for(int i=2;i<=n;i++){
           dp[i]=(dp[i-1]*(2*i-1)*i)%MOD;
       }
       return (int)dp[n]; 
    }
};