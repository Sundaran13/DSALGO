class Solution {
public:
    int solver(int n){
        if(n==0){
            return 0;
        }
        return n%2+solver(n/2);
    }
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for(int i=0;i<=n;i++){
            res[i]=solver(i);
        }
        return res;
    }
};