class Solution {
public:
    int find(vector<int>&prices,int i,int k,bool buy,vector<vector<int>>&v){
        if(i>=prices.size() or k<=0) return 0;
        if(v[i][buy]!=-1)return v[i][buy];
        if(buy){
            return v[i][buy]=max(-prices[i]+find(prices,i+1,k,!buy,v),find(prices,i+1,k,buy,v));
        }
        else{
            return v[i][buy]=max(prices[i]+find(prices,i+1,k-1,!buy,v),find(prices,i+1,k,buy,v));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> v(n,vector<int>(2,-1));
        return find(prices,0,1,1,v);
    }
};