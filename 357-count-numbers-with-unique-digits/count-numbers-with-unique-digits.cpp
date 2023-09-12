class Solution {
public:
    int solver(int n){
        if(n==0)return 1;
        int sum=9;
        for(int i=0;i<n-1;i++){
            sum*=(9-i);
        }
        return sum+solver(n-1);
    }
    int countNumbersWithUniqueDigits(int n) {
       return solver(n);
    }
};