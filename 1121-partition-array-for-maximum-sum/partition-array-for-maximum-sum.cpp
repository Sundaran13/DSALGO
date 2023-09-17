class Solution {
public:
    int solver(vector<int>&arr,int k,int s,vector<int>&dp){
        if(s>=arr.size()){
            return 0;
        }
        if(dp[s]!=-1)return dp[s];
        int n=arr.size();
        int curr_sum=INT_MIN;
        int max_ele=INT_MIN;
        for(int i=s;i<min(s+k,n);i++){
            max_ele=max(max_ele,arr[i]);
            curr_sum=max(curr_sum,solver(arr,k,i+1,dp)+max_ele*(i-s+1));
        }
        return dp[s]=curr_sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+k,0);
        int n=arr.size();
        for(int s=arr.size()-1;s>=0;s--){            
            int curr_sum=INT_MIN;
            int max_ele=INT_MIN;
            for(int i=s;i<min(s+k,n);i++){
                max_ele=max(max_ele,arr[i]);
                curr_sum=max(curr_sum,dp[i+1]+max_ele*(i-s+1));
            }
            dp[s]=curr_sum;
            }
        return dp[0];
    }
};