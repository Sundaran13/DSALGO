typedef long long ll;
class Solution {
public:
    ll m=1e9+7;
    string s;
    ll dp[100001];
    int numDecodings(string &S) {
        s=S;
        for(int i=0;i<=s.size();i++){
            dp[i]=-1;
        }
        
        ll ans=solver(0);
        return ans;
    }
    ll solver(int pos){
        if(pos>=s.size()){
            return 1;
        }
        if(dp[pos]!=-1)return dp[pos];
        if(s[pos]=='0'){
            return dp[pos]=0;
        }
        ll ans = solver(pos+1);
        if(s[pos]=='*'){
            ans*=9;
            if(pos+1<s.size() and s[pos+1]>='0' and s[pos+1]<='9'){
                ans+=solver(pos+2);
            }
            if(pos+1<s.size() and s[pos+1]=='*'){
                ans+=9*solver(pos+2);
            }
            if(pos+1<s.size()and s[pos+1]>='0' and s[pos+1]<='6'){
                ans+=solver(pos+2);
            }
            if(pos+1<s.size() and s[pos+1]=='*'){
                ans=ans+(6*solver(pos+2));
            }
        }
        else if(s[pos]=='1' and pos+1<s.size()){
            if(s[pos+1]>='0' and s[pos+1]<='9'){
                ans+=solver(pos+2);
            }
            else if(s[pos+1]=='*'){
                ans+=9*solver(pos+2);
            }
        }
        else if(s[pos]=='2' and pos+1<s.size()){
            if(s[pos+1]>='0' and s[pos+1]<='6'){
                ans+=solver(pos+2);
            }
            else if(s[pos+1]=='*'){
                ans+=6*solver(pos+2);
            }
        }
        ans=ans%m;
        return dp[pos]=ans;
    }
};