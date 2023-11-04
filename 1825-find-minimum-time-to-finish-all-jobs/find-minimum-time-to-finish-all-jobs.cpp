class Solution {
public:
    int dp[13][1<<13];
    int solver(int idx,int mask,vector<int>&res,int k,int n){
        if(idx==k){
            if(mask==(1<<n)-1){
                return 0;
            }
            else{
                return INT_MAX;
            }
        }
        if(dp[idx][mask]!=-1)return dp[idx][mask];
        int ans=INT_MAX;
        int notset=0;
        for(int i=0;i<n;i++){
            if(((1<<i)&mask)==0){
                notset+=(1<<i);
            }
        }
        int s=notset;
        while(s>0){
            ans=min(ans,max(res[s],solver(idx+1,mask|s,res,k,n)));
            s=((s-1)&notset);
        }
        return dp[idx][mask]=ans;

    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n=jobs.size();
        vector<int> res(1<<n,0);
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                if((i&(1<<j))){
                    res[i]+=jobs[j];
                }
            }
        }
        memset(dp,-1,sizeof dp);
        //sort(res.begin(),res.end(),greater<int>());
        return solver(0,0,res,k,n);
    }
};