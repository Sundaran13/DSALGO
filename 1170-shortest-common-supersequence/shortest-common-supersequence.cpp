class Solution {
public:
    int solver(string&str1,string& str2,int i,int j){
        if(i>=str1.length() or j>=str2.length()){
            return 0;
        }
        if(str1[i]==str2[j]){
            return 1+solver(str1,str2,i+1,j+1);
        }
        else {
            return min(solver(str1,str2,i+1,j),solver(str1,str2,i,j+1));
        }
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string text1=str1,text2=str2;
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=0;i<=text1.size();i++)dp[i][0]=0;
        for(int j=0;j<=text2.size();j++)dp[0][j]=0;
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                    if(text1[i-1]==text2[j-1]){
                        dp[i][j]=1+dp[i-1][j-1];
                    }        
                    else{
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
            string ans="";
        int i=text1.size(),j=text2.size();
        while(i>0 and j>0){
            if(text1[i-1]==text2[j-1]){
                ans+=text1[i-1];
                i--;j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=text1[i-1];
                i--;
            }
            else{
                ans+=text2[j-1];
                j--;
            }
        }
        while(i>0){ans+=text1[i-1];i--;}
        while(j>0){ans+=text2[j-1];j--;}
        reverse(ans.begin(),ans.end());
        return ans;
        //return dp[text1.size()][text2.size()];
    }
};