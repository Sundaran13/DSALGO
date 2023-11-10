class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> s;
        for(int i=0;i<arr.size();i++){
            int j=i-1;
            int x=0,y=arr[i];
            s.insert(y);
            while(j>=0 and x!=y){
                x|=arr[j];
                y|=arr[j];
                s.insert(y);
                j--;
            }
        }
        return s.size();
    }
};