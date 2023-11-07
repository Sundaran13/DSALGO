class Solution {
public:
    int dp[1001][1001];
    int solver(string &s,int start,int end){
        if(start>end){
            return 0;
        }
        if(start==end){
            return 1;
        }
        if(dp[start][end]!=-1)return dp[start][end];
        int res=0;
        if(s[start]==s[end]){
            int left=start+1;
            int right=end-1;
            while(left<=right && s[left]!=s[start]){
                left++;
            } 
            while(left<=right && s[right]!=s[end]){
                right--;
            } 
            if(left<right){   // a....(a...a)....a  , 2 duplicates found for end points (start and end)
                res+=2*solver(s,start+1,end-1)-solver(s,left+1,right-1); 
            } 
            else if(left==right){   // a...(a)....a,  1 duplicate found for end points (start and end)
                res+=2*solver(s,start+1,end-1)+1; 
            }  
            else{    // a(.........)a , no duplicate found for end points (start and end)
                res+=2*solver(s,start+1,end-1)+2; 
            } 
        }
        else{
            res+=solver(s,start+1,end)+solver(s,start,end-1)-solver(s,start+1,end-1);
        }
        return dp[start][end]=res<0 ? res+1000000007 : res%1000000007;
    }
    int countPalindromicSubsequences(string s) {
        memset(dp,-1,sizeof dp);
        return solver(s,0,s.size()-1);
    }
};