class Solution {
public:
    unordered_map<int,int> dp;
    int fib(int n){
        if(n==1 or n==0){
            return 1;
        }
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        return dp[n]=fib(n-1)+ fib(n-2);
    }
    int climbStairs(int n) {
        dp[1]=1;
        dp[0]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+ dp[i-2];
        }
        return dp[n];
    }
};