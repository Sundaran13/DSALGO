class Solution {
public:
    bool solver(string &s, string &p,int i,int j){
        if(i==-1 and j==-1){
            return true;
        }
        if(j==-1){
            return false;
        }
        if(i==-1){
            if(j>=0 and p[j]=='*')return solver(s,p,i,j-2);
            else return false;
        }
        int ch1=0,ch2=0;
        if(p[j]>='a' and p[j]<='z'){
            if(s[i]==p[j]){
                ch2=solver(s,p,i-1,j-1);
            }
        }
        else if(p[j]=='.'){
            ch2=solver(s,p,i-1,j-1);
        }
        else{
            char prev=p[j-1];
            if(prev=='.'){
                ch1=solver(s,p,i-1,j);
                ch2=solver(s,p,i,j-2);
            }
            else{
                if(s[i]==prev){
                    ch1=solver(s,p,i-1,j);
                }
                ch2=solver(s,p,i,j-2);
            }
        }
        return ch1 or ch2;
    }
    bool isMatch(string s, string p) {
        return solver(s,p,s.size()-1,p.size()-1);
    }
};