class Solution {
public:
int ans=0,ind=-1;
 bool f(int i,int j,string &s,vector<vector<int>>&dp)
    {
        if(i>=j)return true;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]!=s[j])
        {
            dp[i][j]=false;
        }
        else
        {
            dp[i][j]=f(i+1,j-1,s,dp);
        }
        return dp[i][j];
    }
    string longestPalindrome(string s) {
        vector<vector<int>>dp(s.length()+1,vector<int>(s.length()+1,-1));
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                if(f(i,j,s,dp))
                {
                   // cout<<i<<" "<<j<<endl;
                    if(ans<j-i+1)
                    {
                        ans=j-i+1;
                        ind=i;
                    }
                }
            }
        }
        return s.substr(ind,ans);
    }
};