class Solution {
public:
    int solver(vector<int>&stoneValue,int i,vector<int>&dp){
        int n=stoneValue.size();
        if(i>=n)return 0;
        if(dp[i]!=INT_MAX)return dp[i];
        int takeOne=stoneValue[i]-solver(stoneValue,i+1,dp);
        int takeTwo=INT_MIN;
        if(i+1<n)takeTwo=stoneValue[i]+stoneValue[i+1]-solver(stoneValue,i+2,dp);
        int takeThree=INT_MIN;
        if(i+2<n)takeThree=stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-solver(stoneValue,i+3,dp);

        return dp[i]=max({takeOne,takeTwo,takeThree});
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size(),INT_MAX);
        int value=solver(stoneValue,0,dp);
        if(value>0){
            return "Alice";
        }
        else if(value<0){
            return "Bob";
        }
        else{
            return "Tie";
        }
    }
};