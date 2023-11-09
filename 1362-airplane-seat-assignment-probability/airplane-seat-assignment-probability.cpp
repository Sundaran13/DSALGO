class Solution {
public:
   
    double solver(int n){
        if(n==1){
            return 1.0;
        }
        return (1.0/n)+((n-2.0)/n)*solver(n-1);
    }
    double nthPersonGetsNthSeat(int n) {
        return solver(n);
    }
};