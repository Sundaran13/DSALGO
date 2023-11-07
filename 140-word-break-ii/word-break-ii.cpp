class Solution {
public:
    vector<string> ans;
    unordered_set<string> st;
    void solver(string &s,unordered_set<string>&st,string curr,int i){
        if(i==s.length()){
            curr.pop_back();
            ans.push_back(curr);
            st.insert(curr);
        }
        if(st.count(curr))return;
        string res="";
        for(int j=i;j<s.length();j++){
            res.push_back(s[j]);
            if(st.count(res)){
                solver(s,st,curr+res+" ",j+1);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto it: wordDict){
            st.insert(it);
        }
        solver(s,st,"",0);
        return ans;
    }
};