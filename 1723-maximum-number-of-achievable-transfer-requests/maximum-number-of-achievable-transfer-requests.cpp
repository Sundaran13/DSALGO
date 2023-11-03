class Solution {
public:
    void solver(int n,vector<vector<int>>&requests,int i,int bitmask,int tot,int &ans){
        if(i==requests.size()){
            vector<int> nums(n,0);
            for(int j=0;j<requests.size();j++){
                if((bitmask&(1<<j))){
                    int x=requests[j][0];
                    int y=requests[j][1];
                    nums[x]--;
                    nums[y]++;
                }
            }
            for(auto it:nums){
                if(it!=0){
                    return;
                }
            }
            ans=max(ans,tot);
            return;
        }
        solver(n,requests,i+1,bitmask,tot,ans);
        solver(n,requests,i+1,bitmask|(1<<i),tot+1,ans);
        return ;
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans=INT_MIN;
        solver(n,requests,0,0,0,ans);
        return ans;
    }
};