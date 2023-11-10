class Solution {
public:
    int mod=1e9+7;
    long long kadanes(vector<int>&arr){
        long long sum=0;
        long long maxsum=0;
        for(int i=0;i<arr.size();i++){
            if(sum<0){
                sum=arr[i];
            }
            else if(sum>=0){
                sum+=arr[i];
            }
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long sum=0;
        for(auto it: arr){
            sum+=it;
        }
        if(k==1){
            return kadanes(arr)%mod;
        }
        else {
            if(sum<0){
                arr.insert(arr.begin(),arr.begin(),arr.end());
                return kadanes(arr)%mod;
            }
            else{
                arr.insert(arr.begin(),arr.begin(),arr.end());
                long long ans=kadanes(arr)%mod;
                return ((k-2)*sum+ans)%mod;
        }
        }

    }
};