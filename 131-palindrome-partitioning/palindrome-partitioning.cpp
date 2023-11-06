class Solution {
public:
    vector<vector<string>>vec;
    bool ispalin(string s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;end--;
        }
        return true;
    }
    void solver(string&s,int index,vector<string>temp){
        if(index>=s.size()){
            vec.push_back(temp);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(ispalin(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                solver(s,i+1,temp);
                temp.pop_back();
            }
        }
        return ;
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solver(s,0,temp);
        return vec;
    }
};