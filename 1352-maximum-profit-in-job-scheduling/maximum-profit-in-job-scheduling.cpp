class Solution {
public:
    map<int,int> dp;
    int solver(int i,vector<vector<int>>&vec,vector<int>&startTime){
        if(i>=vec.size()){
            return 0;
        }
        if(dp.find(i)!=dp.end()){
            return dp[i];
        }
        int number=lower_bound(startTime.begin(),startTime.end(),vec[i][1])-startTime.begin();
        int take=vec[i][2]+solver(number,vec,startTime);
        int notTake=solver(i+1,vec,startTime);
        return dp[i]=max(take,notTake);        
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<vector<int>>vec(n);
        for(int i=0;i<profit.size();i++){
            vec[i].push_back(startTime[i]);
            vec[i].push_back(endTime[i]);
            vec[i].push_back(profit[i]);
        }
        sort(startTime.begin(),startTime.end());
        sort(vec.begin(),vec.end());
        return solver(0,vec,startTime);
    }
};