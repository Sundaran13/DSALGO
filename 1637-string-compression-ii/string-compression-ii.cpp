class Solution {
public:
    //int dp[102][101][101][101];
    int dp[101][101][27][11];
    int solver(string &s,int k,int idx,char prev,int count_curr){
        if(k<0)return 155;
        if(idx>=s.size())return 0;
        if(count_curr>=10){
            count_curr=10;
        }
        if(dp[k][idx][prev-'a'][count_curr]!=-1)return dp[k][idx][prev-'a'][count_curr];
        int ans=155;
        ans=min(ans,solver(s,k-1,idx+1,prev,count_curr));
        if(s[idx]!=prev){
            ans=min(ans,1+solver(s,k,idx+1,s[idx],1));
        }
        else{
            if(count_curr==1 or count_curr==9){
                ans=min(ans,1+solver(s,k,idx+1,prev,count_curr+1));
            }
            else{
                ans=min(ans,solver(s,k,idx+1,prev,count_curr+1));
            }
        }
        return dp[k][idx][prev-'a'][count_curr]=ans;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp,-1,sizeof dp);
        int n=s.size();
        if(n==k)return 0;
        bool allsame=true;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                allsame=false;
                break;
            }
        }
        if(allsame){
            n-=k;
            if(n==1){
                return 1;
            }
            return log10(n)+1+1;
        }
        return solver(s,k,0,'z'+1,0);
    }
};