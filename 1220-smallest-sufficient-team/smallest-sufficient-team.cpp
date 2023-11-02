class Solution {
public:
    vector<int> res;
    int dp[61][1<<17];
    void solver(int i,vector<int>&people_count,int m,int n,vector<int>&ans,int mask){
        if(i==people_count.size()){
            if(mask==(1<<m)-1){
                if(res.size()==0 or ans.size()<res.size())res=ans;
            }
            return;
        }
        if(dp[i][mask]!=-1){
            if(dp[i][mask]<=ans.size())return;
        }
        solver(i+1,people_count,m,n,ans,mask);
        ans.push_back(i);
        solver(i+1,people_count,m,n,ans,mask|people_count[i]);
        ans.pop_back();
        if(ans.size()>0)dp[i][mask]=ans.size();
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n=people.size();
        int m=req_skills.size();
        unordered_map<string,int> mpp;
        for(int i=0;i<m;i++){
            mpp[req_skills[i]]=1<<i;
        }
        vector<int>people_count;
        for(auto it:people){
            int mask=0;
            for(int i=0;i<it.size();i++){
                if(mpp.count(it[i]))mask|=mpp[it[i]];
            }
            people_count.push_back(mask);
        }
        vector<int> ans;
        memset(dp,-1,sizeof dp);
        solver(0,people_count,m,n,ans,0);
        return res;
    }
};