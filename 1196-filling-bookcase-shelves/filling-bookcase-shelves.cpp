class Solution {
public:
    int solver(vector<vector<int>>&books,int i,int remShelfWidth,int maxShelfHeight,int shelfWidth,vector<vector<int>>&dp){
        if(i==books.size()){
            return maxShelfHeight;
        }
        if(dp[i][remShelfWidth]!=-1)return dp[i][remShelfWidth];
        int currShelf=INT_MAX,nextShelf=INT_MAX;
        int bookWidth=books[i][0];
        int bookHeight=books[i][1];
        if(bookWidth<=remShelfWidth){
            currShelf=solver(books,i+1,remShelfWidth-bookWidth,max(bookHeight,maxShelfHeight),shelfWidth,dp);
        }
        nextShelf=maxShelfHeight+solver(books,i+1,shelfWidth-bookWidth,bookHeight,shelfWidth,dp);
        return dp[i][remShelfWidth]=min(currShelf,nextShelf);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<vector<int>> dp(1001,vector<int>(1001,-1));
        return solver(books,0,shelfWidth,0,shelfWidth,dp);
    }
};