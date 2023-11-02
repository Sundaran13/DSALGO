class Solution {
public:
    int m;
    int t;
    vector<int>dp;
    bool solver(int mask,int score){
        if(dp[mask]!=-1)return dp[mask];
        for(int i=0;i<m;i++){
            int cmask=1<<i;
            if((mask&cmask)==0){
                if(score+i+1>=t or solver((mask|cmask),score+i+1)==false)return dp[mask]=1;
            }
        }
        return dp[mask]=0;
    }
    bool canIWin(int maxChoosableInteger, int dt) {
        m=maxChoosableInteger;
        t=dt;
        dp.resize(1<<m,-1);
        if(m*(m+1)<t)return false;
        return solver(0,0);
    }
};