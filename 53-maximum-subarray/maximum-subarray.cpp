class Solution {
public:
    int solver(vector<int>&nums,int l,int r){
        if(l>r){
            return INT_MIN;
        }
        int m=l+(r-l)/2,ml=0,mr=0;
        int lmax=solver(nums,l,m-1);
        int rmax=solver(nums,m+1,r);
        for(int i=m-1,sum=0;i>=l;i--){
            sum+=nums[i];
            ml=max(ml,sum);
        }
        for(int i=m+1,sum=0;i<=r;i++){
            sum+=nums[i];
            mr=max(mr,sum);
        }
        return max(max(lmax,rmax),ml+mr+nums[m]);
    }
    int maxSubArray(vector<int>& nums) {
        return solver(nums,0,nums.size()-1);
    }
};