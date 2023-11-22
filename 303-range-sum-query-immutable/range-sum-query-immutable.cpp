class NumArray {
public:
    vector<int>&presum;
    void solver(int i,vector<int>&nums){
        if(i>=nums.size()){
            return;
        }
        presum[i]+=presum[i-1];
        solver(i+1,nums);
    }
    NumArray(vector<int>& nums):presum(nums){
        solver(1,nums);
    }
    
    int sumRange(int left, int right) {
        if(left==0)return presum[right];
        return presum[right]-presum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */