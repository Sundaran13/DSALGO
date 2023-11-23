class Solution {
public:
    string solver(string curr,string prev,int n){
        if(curr==prev){
            return curr;
        }
        string temp=curr;
        for(int i=0;i<n;i++){
            if(temp[i]=='L' and i-1>=0 and temp[i-1]=='.'){
                if(i-2>=0 and temp[i-2]=='R'){
                    continue;
                }
                curr[i-1]=curr[i];
            }
            if(temp[i]=='R' and i+1<n and temp[i+1]=='.'){
                if(i+2<n and temp[i+2]=='L'){
                    continue;
                }
                curr[i+1]=curr[i];
            }
        }
        return solver(curr,temp,n);
    }
    string pushDominoes(string dominoes) {
        return solver(dominoes,"",dominoes.size());
    }
};