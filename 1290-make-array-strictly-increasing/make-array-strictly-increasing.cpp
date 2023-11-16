class Solution {
public:
    map<pair<int,int>,int> dp;
    int solver(vector<int>&arr1,vector<int>&arr2,int idx,int prev){
        if(idx==arr1.size()){
            return 0;
        }
        if(dp.find({idx,prev})!=dp.end())return dp[{idx,prev}];
        int take=1e9,nottake=1e9;
        int ind=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        if(ind<arr2.size()){
            take=1+solver(arr1,arr2,idx+1,arr2[ind]);
        }
        if(arr1[idx]>prev){
            nottake=solver(arr1,arr2,idx+1,arr1[idx]);
        }
        return dp[{idx,prev}]=min(take,nottake);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        //memset(dp,-1,sizeof dp);
        int res=solver(arr1,arr2,0,-1);
        return res>=1e9?-1:res;
    }
};