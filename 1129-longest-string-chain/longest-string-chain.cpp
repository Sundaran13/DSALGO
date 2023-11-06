class Solution {
public:
    unordered_map<string,int> dp;
    set<string> st;
    int solver(string &s){
        if(st.find(s)==st.end()){
            return 0;
        }
        if(dp.find(s)!=dp.end())return dp[s];
        int cl=1;
        for(int i=0;i<s.length();i++){
            string nw_wrd=s.substr(0,i)+s.substr(i+1);
            cl=max(cl,1+solver(nw_wrd));
        }
        return dp[s]=cl;
    }
    int longestStrChain(vector<string>& words) {
        int ans=INT_MIN;
        for(auto it:words){
            st.insert(it);
        }
        for(auto it:words){
            ans=max(ans,solver(it));
        }
        return ans;
    }
};