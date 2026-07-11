class Solution {
public:
    void solve(int node,vector<vector<int>>& adj,vector<int>&vis,int &n, int &degsum){
        vis[node]=1;
        n+=1;
        degsum+=adj[node].size();
        for(auto &it:adj[node]){
            if(!vis[it]){
                solve(it,adj,vis,n,degsum);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int node=0;
                int degsum=0;
                solve(i,adj,vis,node,degsum);

                int edge=degsum/2;
                if(edge==node*(node-1)/2) ans++;
            }
        }

        return ans;
    }
};