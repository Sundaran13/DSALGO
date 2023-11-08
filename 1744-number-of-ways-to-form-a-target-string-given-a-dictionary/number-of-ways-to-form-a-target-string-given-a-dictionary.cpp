class Solution {
public:
    int mod=1000000007;
    vector<vector<int>>dp;
    vector<vector<int>> freq;
    long solver(vector<string>&words,string &target,int i,int j){
        if(j==target.size()){
            return 1;
        }
        if(i==words[0].size() or words[0].size()-i<target.size()-j){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        long count=0;
        int currpos=target[j]-'a';
        count=(freq[i][currpos]*solver(words,target,i+1,j+1))%mod;
        count=(count+solver(words,target,i+1,j))%mod;
        return dp[i][j]=count%mod;
    }
    int numWays(vector<string>& words, string target) {
        dp.resize(words[0].size(),vector<int>(target.size(),-1));
        freq.resize(words[0].size(),vector<int>(26,0));
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[0].size();j++){
                int currpos=words[i][j]-'a';
                freq[j][currpos]++;
            }
        }
        return solver(words,target,0,0)%mod;
    }
};