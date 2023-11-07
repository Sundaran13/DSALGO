class Solution {
public:
    bool solver(string s,unordered_set<string>&st,int startindex,unordered_map<int,bool>&dp){
        if(st.empty()){
            return false;
        }
        if(startindex==s.length()){
            return true;
        }
        if(dp.find(startindex)!=dp.end())return dp[startindex];
        for(int j=startindex+1;j<=s.length();j++){
            if(st.count(s.substr(startindex,j-startindex)) and solver(s,st,j,dp)){
                return dp[startindex]=true;
            }
        }
        return dp[startindex]=false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st;
        // for(auto it:words){
        //     st.insert(it);
        // }
        sort(words.begin(),words.end(),[](const string& a,const string& b){
            return a.length()<b.length();
        });
        vector<string> ans;
        for(const string& it: words){
            unordered_map<int,bool> dp;
            if(solver(it,st,0,dp)){
                ans.push_back(it);
            }
            st.insert(it);
        }
        return ans;
    }
};