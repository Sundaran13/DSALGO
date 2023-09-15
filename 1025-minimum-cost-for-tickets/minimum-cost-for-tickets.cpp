class Solution {
public:
   // int cost_day,cost_week,cost_month;
    int solver(vector<int>&days,vector<int>&costs,int si,vector<int>&dp){
        int n=days.size();
        if(si>=n)return 0;
        if(dp[si]!=-1)return dp[si];
        int cost_day=costs[0]+solver(days,costs,si+1,dp);

        int i;
        for(i=si;i<n and days[i]<days[si]+7 ; i++);
        int cost_week=costs[1]+solver(days,costs,i,dp);
        for(i=si;i<n and days[i]<days[si]+30 ; i++);
        int cost_month= costs[2]+ solver(days,costs,i,dp);
        return dp[si]=min({cost_day,cost_week,cost_month});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1,-1);
        return solver(days,costs,0,dp);
    }
};