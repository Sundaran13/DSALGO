class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n=nums.size(),i,ans=0,cnt,prev;
        stack<pair<int,int>>st;
        st.push({nums[n-1],0});
        for(int i=n-2;i>=0;i--){
            cnt=0;
            while(!st.empty() and st.top().first<nums[i]){
                cnt=max(cnt+1,st.top().second);
                st.pop();
            }
            ans=max(ans,cnt);
            st.push({nums[i],cnt});
        }
        return ans;
    }
};