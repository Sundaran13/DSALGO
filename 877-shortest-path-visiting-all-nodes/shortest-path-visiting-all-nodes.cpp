class Solution {
public:
    class tuple{
        public:
        int node;
        int mask;
        int cost;
        tuple(int node,int mask,int cost){
            this->node=node;
            this->mask=mask;
            this->cost=cost;
        }
    };
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<tuple> q;
        set<pair<int,int>>vis;
        int all=(1<<n)-1;
        for(int i=0;i<n;i++){
            int maskval=(1<<i);
            tuple thisnode(i,maskval,1);
            q.push(thisnode);
            vis.insert({i,maskval});
        }
        while(!q.empty()){
            tuple curr=q.front();
            q.pop();
            if(curr.mask==all){
                return curr.cost-1;
            }
            for(auto &adj:graph[curr.node]){
                int maskvis=curr.mask;
                maskvis=maskvis|(1<<adj);
                tuple thisnode(adj,maskvis,curr.cost+1);

                if(vis.find({adj,maskvis})==vis.end()){
                    vis.insert({adj,maskvis});
                    q.push(thisnode);
                }
            }
        }
        return -1;
    }
};