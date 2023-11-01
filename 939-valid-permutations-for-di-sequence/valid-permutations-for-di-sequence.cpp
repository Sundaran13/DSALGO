class Solution {
public:
    int vis[201];
    int dp[201][201];
    long long int mod=1000000007;
    int solver(string &s,int index,int prev){
        if(index==s.size()){
            return 1;
        }
        if(dp[index][prev]!=-1)return dp[index][prev];
        long long int cnt=0;
        if(s[index]=='D'){
            for(int i=0;i<prev;i++){
                if(vis[i]==0){
                    vis[i]=1;
                    cnt+=(solver(s,index+1,i))%mod;
                    vis[i]=0;
                }
            }
        }
        else{
            for(int i=prev+1;i<=s.size();i++){
                if(vis[i]==0){
                    vis[i]=1;
                    cnt+=(solver(s,index+1,i))%mod;
                    vis[i]=0;
                }
            }
        }
        return dp[index][prev]=(cnt)%mod;
    }
    int numPermsDISequence(string s) {
        long long int ans=0;
        memset(vis,0,sizeof vis);
        memset(dp,-1,sizeof dp);
        for(int i=0;i<=s.size();i++){
            vis[i]=1;
            ans+=solver(s,0,i);
            vis[i]=0;
        }
        return ans%mod;
    }
};