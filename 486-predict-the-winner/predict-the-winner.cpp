class Solution {
public:
    int solver(vector<int>&nums,int i,int j,bool player){
        if(i>j)return -1;
        if(i==j)return nums[i];
        if(player){
            return max(nums[i]+solver(nums,i+1,j,!player),nums[j]+solver(nums,i,j-1,!player));
        }
        else{
            return min(-nums[i]+solver(nums,i+1,j,!player),-nums[j]+solver(nums,i,j-1,!player));
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        if(solver(nums,0,nums.size()-1,true)>=0){
            return true;
        }
        else{
            return false;
        }
    }
};