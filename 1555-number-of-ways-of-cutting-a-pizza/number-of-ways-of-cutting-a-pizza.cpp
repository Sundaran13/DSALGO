class Solution {
public:
    long long MOD=1000000007;
    long long dp[51][51][11];
    bool isValid(vector<string>&pizza,int startRow,int endRow,int startCol,int endCol){
        for(int i=startRow;i<=endRow;i++){
            for(int j=startCol;j<=endCol;j++){
                if(pizza[i][j]=='A'){
                    return true;
                }
            }
        }
        return false;
    }
    int solver(vector<string>&pizza,int startRow,int startCol,int cutsleft){
        int m=pizza.size(),n=pizza[0].size();
        if(cutsleft==0)return 1;
        if(dp[startRow][startCol][cutsleft]!=-1)return dp[startRow][startCol][cutsleft];
        long long ans=0;
        for(int row=startRow;row<m-1;row++){
            bool upperhalfvalid=isValid(pizza,startRow,row,startCol,n-1);
            bool lowerhalfvalid=isValid(pizza,row+1,m-1,startCol,n-1);
            if(upperhalfvalid and lowerhalfvalid){
                int nextways = solver(pizza,row+1,startCol,cutsleft-1);
                ans=(ans+nextways)%MOD;
            }
        }
        for(int col=startCol;col<n-1;col++){
            bool lefthalfvalid=isValid(pizza,startRow,m-1,startCol,col);
            bool righthalfvalid=isValid(pizza,startRow,m-1,col+1,n-1);
            if(lefthalfvalid and righthalfvalid){
                int nextways=solver(pizza,startRow,col+1,cutsleft-1);
                ans=(ans+nextways)%MOD;
            }
        }
        return dp[startRow][startCol][cutsleft]=ans;
    }
    int ways(vector<string>& pizza, int k) {
        int m=pizza.size(),n=pizza[0].size();
        if(k==1)return (isValid(pizza,0,m-1,0,n-1)?1:0);
        memset(dp,-1,sizeof(dp));
        int ans=solver(pizza,0,0,k-1);
        return ans;
    }
};