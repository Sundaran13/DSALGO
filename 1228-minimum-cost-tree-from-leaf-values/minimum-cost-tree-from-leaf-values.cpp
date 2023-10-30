class Solution {
public:
    int dp[41][41];
    int solver(vector<int>&arr,map<pair<int,int>,int>&maxi,int left,int right){
        if(left==right){
            return 0;
        }
        int ans=INT_MAX;
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        //les than right and not equal bcoz we don't want this to go out of bounds.
        for(int i=left;i<right;i++){
            ans=min(ans,maxi[{left,i}]*maxi[{i+1,right}]+solver(arr,maxi,left,i)+solver(arr,maxi,i+1,right));
        }
        return dp[left][right]=ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int>maxi;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<arr.size();i++){
            maxi[{i,i}]=arr[i];
            for(int j=i+1;j<arr.size();j++){
                maxi[{i,j}]=max(maxi[{i,j-1}],arr[j]);
            }
        }
        return solver(arr,maxi,0,arr.size()-1);
    }
};