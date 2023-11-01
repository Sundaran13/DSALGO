class Solution {
public:
    int dp[501][501];
    int solver(vector<int>&stones,int i,int j,int suffix[]){
        if(i>=j)return 0;
        if(i+1==j)return min(stones[i],stones[j]);
        if(dp[i][j]!=-1)return dp[i][j];
        int res=0;
        for(int k=i;k<j;k++){
            int left=suffix[k+1]-suffix[i];
            int right=suffix[j+1]-suffix[k+1];
            if(left>right){
                res=max(res,right+solver(stones,k+1,j,suffix));
            }
            else if(left<right){
                res=max(res,left+solver(stones,i,k,suffix));
            }
            else{
                res=max(res,max(solver(stones,i,k,suffix),solver(stones,k+1,j,suffix))+right);
            }
        }
        return dp[i][j]=res;
    }
    int stoneGameV(vector<int>& stones) {
        int suffix[stones.size()+1];
        memset(dp,-1,sizeof dp);
        int sum=0;
        for(int i=0;i<stones.size();i++){
            suffix[i+1]=suffix[i]+stones[i];
        }
        return solver(stones,0,stones.size()-1,suffix);
    }
};