class Solution {
  typedef pair<int,int> p;
public:
    int networkDelayTime(vector<vector<int>>& nums, int n, int k) {
        vector<vector<p>> adj(n+1);
        for(auto &it: nums){
            adj[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,k});
        vector<int> dist(n+1,1e9);
        dist[k]=0;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int time=it.first;
            int node=it.second;

            for(auto &it: adj[node]){
                int adjNode=it.first;
                int t=it.second;

                if(time+t < dist[adjNode]){
                    dist[adjNode]=time+t;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }


        
        int ans=0;
        for(int i=1;i<n+1;i++){
            if(dist[i]==1e9) return -1;
            ans=max(ans,dist[i]);
        }
      return ans;


    }
};