class Solution {
public:
    int dp[1001][1001];
    int solver(vector<int>&arr,unordered_map<int,int>&mp,int i,int j){
        if(mp.find(arr[i]+arr[j])==mp.end()){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=1+solver(arr,mp,j,mp[arr[i]+arr[j]]);
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        int mAx=0;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                if(mp.find(arr[i]+arr[j])==mp.end()){
                    continue;
                }
                mAx=max(mAx,solver(arr,mp,i,j)+2);
            }
        }
        return mAx;
    }
};