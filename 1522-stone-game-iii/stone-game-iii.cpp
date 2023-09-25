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
        vector<int> dp(stoneValue.size()+3,0);
        for(int i=stoneValue.size()-1;i>=0;i--){
            int n=stoneValue.size();
            int takeOne=stoneValue[i]-dp[i+1];
            int takeTwo=INT_MIN;
            if(i+1<n)takeTwo=stoneValue[i]+stoneValue[i+1]-dp[i+2];
            int takeThree=INT_MIN;
            if(i+2<n)takeThree=stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[i+3];

            dp[i]=max({takeOne,takeTwo,takeThree});
        }
        int value=dp[0];
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