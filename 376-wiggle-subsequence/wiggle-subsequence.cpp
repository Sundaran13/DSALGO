class Solution {
public:
    int solver(vector<int>&nums,int curr,int prev,bool positive){
        if(curr>=nums.size() or prev>=nums.size()){
            return 0;
        }
        if(positive){
            if(nums[prev]>nums[curr]){
                return 1+solver(nums,curr+1,curr,!positive);
            }
            else{
                return solver(nums,curr+1,curr,positive);
            }
        }
        else{
            if(nums[prev]<nums[curr]){
                return 1+solver(nums,curr+1,curr,!positive);
            }
            else{
                return solver(nums,curr+1,curr,positive);
            }
        }
    }
    int wiggleMaxLength(vector<int>& nums) {
        return 1+max(solver(nums,1,0,true),solver(nums,1,0,false));
    }
};