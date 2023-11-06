class Solution {
public:
    unordered_map<string,bool> dp;
    bool solver(string s,set<string>&st){
        if(s.length()==0){
            return true;
        }
        if(dp.find(s)!=dp.end())return dp[s];
        for(int i=1;i<=s.length();i++){
            if(st.find(s.substr(0,i))!=st.end() and solver(s.substr(i),st)){
                return dp[s]=true;
            }
        }
        return dp[s]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto it:wordDict){
            st.insert(it);
        }
        return solver(s,st);
    }
};