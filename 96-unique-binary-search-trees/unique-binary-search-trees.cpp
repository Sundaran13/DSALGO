class Solution {
public:
    int solver(int n){
        if(n<=1){
            return 1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=solver(i-1)*solver(n-i);
        }
        return ans;
    }
    int numTrees(int n) {
        return solver(n);
    }
};