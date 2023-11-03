class Solution {
public:
    int n,m,ans;
    int dp[8][8][255][255];
    vector<vector<char>>a;
    bool is(int i,int j){
        if(a[i][j]!='.')return 0;
        if(i-1>=0 and j-1>=0 and a[i-1][j-1]=='&')return 0;
        if(i-1>=0 and j+1<m and a[i-1][j+1]=='&')return 0;
        if(j-1>=0 and a[i][j-1]=='&')return 0;
        if(j+1<m and a[i][j+1]=='&')return 0;
        return 1;
    }
    int solver(int r,int c,int premask,int currmask){
        if(r==n)return 0;
        if(c==m)return solver(r+1,0,currmask,0);
        int ans= dp[r][c][premask][currmask];
        if(ans!=-1)return ans;
        ans=0;
        if(is(r,c)){
            a[r][c]='&';
            ans=max(ans,1+solver(r,c+1,premask,currmask|(1<<c)));
            a[r][c]='.';
        }
        ans=max(ans,solver(r,c+1,premask,currmask));
        return dp[r][c][premask][currmask]=ans;
    }
    int maxStudents(vector<vector<char>>& seats) {
        a=seats;
        n=seats.size();
        m=seats[0].size();
        memset(dp,-1,sizeof dp);
        return solver(0,0,0,0);
    }
};