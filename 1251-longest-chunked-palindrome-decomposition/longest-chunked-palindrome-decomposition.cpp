class Solution {
public:
    int res=1;
    unordered_map<string,int> dp;
    int solver(string&text,int l,int r){
        if(l>r)return 0;
        if(dp.count(text.substr(l,r-l+1)))return dp[text.substr(l,r-l+1)];
        for(int len=1;len<=(r-l+1)/2;len++){
            if(text.substr(l,len)==text.substr(r-len+1,len)){
                res=max(res,2+solver(text,l+len,r-len));
            }
        }
        return dp[text.substr(l,r-l+1)]=res;
    }
    int longestDecomposition(string text) {
        return solver(text,0,text.length()-1);
    }
};