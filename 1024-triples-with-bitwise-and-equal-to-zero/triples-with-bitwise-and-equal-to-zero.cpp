class Solution {
public:
    void solver(int i,unsigned currnum,unsigned num,int cnt[],int &res){
        if(i==16){
            res+=cnt[currnum];
            return;
        }
        if(((num>>i)&1)==0){
            solver(i+1,currnum+(1<<i),num,cnt,res);
        }
        solver(i+1,currnum,num,cnt,res);
    }
    int countTriplets(vector<int>& nums) {
        int res=0;
        int cnt[1<<16]={0};
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                cnt[nums[i]&nums[j]]++;
            }
        }
        for(auto num:nums){
            solver(0,0,num,cnt,res);
        }
        return res;
    }
};