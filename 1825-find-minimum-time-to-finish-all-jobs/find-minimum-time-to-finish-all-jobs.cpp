class Solution {
public:
    bool solver(vector<int> worker,int mid,vector<int>&jobs,int idx){
        if(idx>=jobs.size()){
            return true;
        }
        int curr=jobs[idx];
        for(int i=0;i<worker.size();i++){
            if(worker[i]+curr<=mid){
                worker[i]+=curr;
                if(solver(worker,mid,jobs,idx+1)){
                    return true;
                }
                worker[i]-=curr;
            }
            if(worker[i]==0){
                break;
            }
        }
        return false;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int sum=0;
        for(auto it:jobs){
            sum+=it;
        }
        sort(jobs.begin(),jobs.end(),greater<int>());
        int l=jobs[0],r=sum;
        while(l<r){
            int mid=(l+r)/2;
            vector<int> worker(k,0);
            if(solver(worker,mid,jobs,0)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};