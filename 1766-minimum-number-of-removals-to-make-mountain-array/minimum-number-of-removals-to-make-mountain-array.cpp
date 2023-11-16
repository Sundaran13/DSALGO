class Solution {
public:
    int lis[1001][1001];
    int lds[1001][1001];
    int LIS(vector<int>&nums,int i,int prev,int previ){
        if(i<0)return 0;
        if(lis[i][previ]!=-1)return lis[i][previ];
        int nottake=LIS(nums,i-1,prev,previ);
        int take=0;
        if(nums[i]<prev){
            take=1+LIS(nums,i-1,nums[i],i);
        }
        return lis[i][previ]=max(take,nottake);
    }
    int LDS(vector<int>&nums,int i,int prev,int previ){
        if(i>=nums.size())return 0;
        if(lds[i][previ]!=-1)return lds[i][previ];
        int nottake=LDS(nums,i+1,prev,previ);
        int take=0;
        if(nums[i]<prev){
            take=1+LDS(nums,i+1,nums[i],i);
        }
        return lds[i][previ]=max(take,nottake);
    }
    int minimumMountainRemovals(vector<int>& nums) {
        memset(lis,-1,sizeof lis);
        memset(lds,-1,sizeof lds);
        int n=nums.size(),total=0;
        for(int i=0;i<n;i++){
            int inc=LIS(nums,i-1,nums[i],i);
            if(inc==0)continue;
            int dec=LDS(nums,i+1,nums[i],i);
            if(dec==0)continue;
            total=max(total,inc+dec+1);
        }
        return nums.size()-total;
    }
};