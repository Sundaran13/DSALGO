class Solution {
public:
    int dp[98765];
    int solver(int mask,string& target,vector<vector<int>>&arr,int allmask){
        if(mask==allmask){
            return 0;
        }
        if(dp[mask]!=-1)return dp[mask];
        else{
            int q=51;
            for(vector<int> word :arr){
                int newmask=mask;
                for(int i=0;i<target.size();i++){
                    if((mask&1<<i)==0 and word[target[i]-'a']){
                        newmask|=1<<i;
                        word[target[i]-'a']--;
                    }
                    if(mask!=newmask){
                        q=min(q,1+solver(newmask,target,arr,allmask));
                    }
                }
            }
            return dp[mask]=q;
        }
    }
    int minStickers(vector<string>& stickers, string target) {
        vector<vector<int>>arr(stickers.size());
        for(int i=0;i<stickers.size();i++){
            vector<int>c(26,0);
            for(char a : stickers[i]){
                c[a-'a']++;
            }
            arr[i]=c;
        }
        int allmask=(1<<target.length())-1;
        memset(dp,-1,sizeof dp);
        int val=solver(0,target,arr,allmask);
        return val<51?val:-1;
    }
};