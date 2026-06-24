class Solution {
public:
    bool solve(int node,vector<vector<int>>& adj, vector<int> &vis, vector<int> &pathvis, vector<int> &check){
         vis[node]=1;
         pathvis[node]=1;
        //  check[node]=0;
         for(auto &it: adj[node]){
            if(!vis[it]){
                if(solve(it,adj,vis,pathvis,check)==true){
                    check[it]=0;
                    return true;
                }
            }
            else if(pathvis[it]){
                    check[it]=0;
                    return true;
            }
         }

         check[node]=1;
         pathvis[node]=0;
         return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> check(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                solve(i,adj,vis,pathvis,check);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }

        return ans;
    }
};