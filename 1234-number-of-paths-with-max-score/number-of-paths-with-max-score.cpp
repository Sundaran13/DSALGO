class Solution {
public:
    int mod=1e9+7;
    map<pair<int,int>,pair<int,int>> dp;
    pair<int,int> solver(vector<string>&board,int i,int j,int n,int m){
        if(i==0 and j==0)return {0,1};
        if(i<0 or j<0 or i>=n or j>=m or board[i][j]=='X')return {INT_MIN,0};
        int no=0,cnt=0;

        if(dp.find({i,j})!=dp.end())return dp[{i,j}];

        if(board[i][j]!='S')no=board[i][j]-'0';
        auto a=solver(board,i-1,j,n,m);
        auto b=solver(board,i,j-1,n,m);
        auto c=solver(board,i-1,j-1,n,m);

        int curr=max({a.first,b.first,c.first});

        if(curr==a.first)cnt+=a.second;
        if(curr==b.first)cnt+=b.second;
        if(curr==c.first)cnt+=c.second;

        return dp[{i,j}]={(curr+no)%mod,cnt%mod};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        auto ans=solver(board,board.size()-1,board[0].size()-1,board.size(),board[0].size());
        if(ans.first<0)return {0,0};
        return {ans.first%mod,ans.second%mod};
    }
};