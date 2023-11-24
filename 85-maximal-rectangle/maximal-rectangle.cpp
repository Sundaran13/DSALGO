class Solution {
public:
        //stack<int> st;
    void nse(vector<int>&next,vector<int>&heights){
        stack<int> st;
        st.push(heights.size());
        for(int i=heights.size()-1;i>=0;i--){
            while(st.top()!=heights.size() and heights[st.top()]>=heights[i]){
                st.pop();
            }
            next[i]=st.top();
            st.push(i);
        }
    }
    void pse(vector<int>&prev,vector<int>&heights){
        stack<int> st;
        st.push(-1);
        for(int i=0;i<heights.size();i++){
            while(st.top()!=-1 and heights[st.top()]>=heights[i]){
                st.pop();
            }
            prev[i]=st.top();
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> prev(n);
        vector<int> next(n);
        nse(next,heights);
        pse(prev,heights);
        int ans=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int h=heights[i];
            int w=next[i]-prev[i]-1;
            int temp_area=h*w;
            ans=max(ans,temp_area);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> heights(matrix[0].size(),0);
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]-'0'==1){
                    heights[j]++;
                }
                else{
                    heights[j]=0;
                }
            }
            int temp=largestRectangleArea(heights);
            ans=max(ans,temp);
        }
        return ans;
    }
};