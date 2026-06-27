class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& nums, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it: nums){
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        dist[src]=0;
        q.push({0,{src,0}});

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int step=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(step > k) continue;
            for(auto &it: adj[node]){
                int adjNode=it.first;
                int price=it.second;
                if(cost+price < dist[adjNode] && step<=k){
                    dist[adjNode]=cost+price;
                    q.push({step+1,{adjNode,cost+price}});
                }
            }
        }
        
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};