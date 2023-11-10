class Solution {
public:
    int maxi=0;
    unordered_set<int> st;
    void solver(vector<int>&arr,int i){
        if(i>=arr.size()){
            return ;
        }
        int j=i-1;
        int x=0,y=arr[i];
        st.insert(y);
        while(j>=0 and x!=y){
            x|=arr[j];
            y|=arr[j];
            st.insert(y);
            j--;
        }
        solver(arr,i+1);
       
    }
    int subarrayBitwiseORs(vector<int>& arr) {
        solver(arr,0);
        return st.size();
    }
};