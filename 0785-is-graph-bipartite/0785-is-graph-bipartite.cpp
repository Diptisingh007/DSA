class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int> &col,int color){
        col[node]=color;

        for(auto &it: adj[node]){
            if(col[it]==-1){
                if(dfs(it,adj,col,!color)==false){
                    return false;
                }
            }
            else if(col[it]==color){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> vis(n,0);
        vector<int> col(n,-1);
        int color=0;
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(dfs(i,adj,col,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};