class Solution {
public:
    int ans=0,ind=0;
    bool ispalin(string&s,int i,int j){
        if(i>=j){
            return true;
        }
        if(s[i]!=s[j]){
            return false;
        }
        return ispalin(s,i+1,j-1);
    }
    string longestPalindrome(string s) {
        int n=s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispalin(s,i,j)){
                    if(j-i+1>ans){
                        ans=j-i+1;
                        ind=i;
                    }
                }
            }
        }
        return s.substr(ind,ans);
    }
};