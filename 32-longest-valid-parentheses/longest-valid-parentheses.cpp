class Solution {
public:
    int solver(string &s,int idx){
        if(idx<=0){
            return 0;
        }
        int ans=0;
        if(s[idx]==')'){
            if(idx>0 and s[idx-1]=='('){
                ans+=2;
                ans+=solver(s,idx-2);
            }
            else if(idx>0 and s[idx-1]==')'){
                int prevlen=solver(s,idx-1);
                if(prevlen>0 and idx-prevlen-1>=0 and s[idx-prevlen-1]=='('){
                    ans+=2;
                    ans+=prevlen;
                    ans+=solver(s,idx-prevlen-2);
                }
            }
        }
        return ans;
    }
    int longestValidParentheses(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,solver(s,i));
        }
        return ans;
    }
};