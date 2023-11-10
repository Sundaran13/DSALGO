class Solution {
public:
    int dp[100000][3];
    int solver(vector<int>&arr,int i,char sign){
        if(i>=arr.size()){
            return 0;
        }
        if(dp[i][sign-60]!=-1)return dp[i][sign-60];
        if(sign=='>'){
            if(arr[i]>arr[i-1]){
                return dp[i][sign-60]=1+solver(arr,i+1,'<');
            }
            else{
                return dp[i][sign-60]=0;
            }
        }
        else{
            if(arr[i]<arr[i-1]){
                return dp[i][sign-60]=1+solver(arr,i+1,'>');
            }
            else{
                return dp[i][sign-60]=0;
            }
        }
    }
    int maxTurbulenceSize(vector<int>& arr) {
        int max1=0;
        memset(dp,-1,sizeof dp);
        for(int i=1;i<=arr.size();i++){
            max1=max(max1,solver(arr,i,'<'));
            max1=max(max1,solver(arr,i,'>'));
        }
        return max1+1;

    }
};