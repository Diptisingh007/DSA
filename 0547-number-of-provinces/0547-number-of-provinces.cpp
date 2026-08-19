class Solution {
public:
    void solve(int node,vector<vector<int>> &adj,vector<int> &vis){
        vis[node]=1;

        for(auto &it: adj[node]){
            if(!vis[it]){
                solve(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<vector<int>> adj(n+1);
         
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               if(nums[i][j]==1 && i!=j){
                  adj[i].push_back(j);
                  adj[j].push_back(i);
               }
            }
        }

        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                solve(i,adj,vis);
            }
        }

      return cnt;
    }
};