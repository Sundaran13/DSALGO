//#define MOD 1e9+7
class Solution {
public:
    long long int MOD=1e9+7;
    long long solver(long long n){
        if(n==1){
            return 1;
        }
        return ((2*n-1)*n*solver(n-1))%MOD;
    }
    int countOrders(int n) {
       return solver(n); 
    }
};