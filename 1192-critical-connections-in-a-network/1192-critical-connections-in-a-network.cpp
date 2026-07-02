class Solution {
public:
    int time=1;
    void solve(int node, int parent, vector<vector<int>> &adj,vector<int>&vis,vector<int>&low,vector<int>&tin,vector<vector<int>> &ans){
        
        vis[node]=1;
        low[node]=tin[node]=time;
        time++;

        for(auto &it: adj[node]){
            if(it==parent) continue;
            if(vis[it]){
                low[node]=min(low[node],low[it]);
            }
            else{
                solve(it,node,adj,vis,low,tin,ans);
                low[node]=min(low[node],low[it]);
                if(low[it] > tin[node]){
                    ans.push_back({it,node});
                }
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& nums) {
        vector<vector<int>> adj(n);
        for(auto &it: nums){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n,0);
        vector<int> low(n,0);
        vector<int> tin(n,0);
        vector<vector<int>> ans;

        solve(0,-1,adj,vis,low,tin,ans);

        return ans;
    }
};