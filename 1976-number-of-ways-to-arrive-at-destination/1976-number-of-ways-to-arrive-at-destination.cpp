class Solution {
    typedef pair<long long ,int> p;
    int mod=1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<p>> adj(n);
        for(auto &it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,0});
        vector<long long> dist(n,LLONG_MAX);
        dist[0]=0;
        vector<int> ans(n,0);
        ans[0]=1;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long long time=it.first;
            int node=it.second;

            for(auto &it: adj[node]){
                int adjNode=it.first;
                int t= it.second;

                if(time+t < dist[adjNode]){
                    dist[adjNode]=time+t;
                    pq.push({dist[adjNode],adjNode});
                    ans[adjNode]=ans[node];
                }
                else if(time+t==dist[adjNode]){
                    ans[adjNode]=(ans[node]+ans[adjNode])%mod;
                }
            }
        }

        return ans[n-1];
    }
};