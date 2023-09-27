class Solution {
public:
    string solver(vector<int>&cost,int target,int idx,vector<vector<string>>&dp){
        if(target==0)return "";
        if(target<0 or idx>=9)return "0";
        if(dp[idx][target]!="-1")return dp[idx][target];
        string include=to_string(idx+1)+solver(cost,target-cost[idx],0,dp);
        string exclude=solver(cost,target,idx+1,dp);
        return dp[idx][target]=getBigger(include,exclude);
    }
    string getBigger(string &s1,string &s2){
        string t="0";
        if(s1.find(t)!=std::string::npos)return s2;
        if(s2.find(t)!=std::string::npos)return s1;
        if(s1.length()>s2.length())return s1;
        else return s2;
    }
    string largestNumber(vector<int>& cost, int target) {
        int n=cost.size();
        vector<vector<string>> dp(cost.size(),vector<string>(target+1,"-1"));
        return solver(cost,target,0,dp);
    }
};