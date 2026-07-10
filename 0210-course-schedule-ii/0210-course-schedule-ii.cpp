class Solution {
public:
 vector<int> topoSort(int V, vector<vector<int>>& edges){
        int n=edges.size();
        vector<int> ans;
        vector<int> indeg(V,0);
        vector<vector<int>> adj(V);
         
        for(auto &it: edges){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
         
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
         
        while(!q.empty()){
            int node=q.front();
            q.pop();
             
            ans.push_back(node);
             
            for(auto it: adj[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
         
        return ans;
     }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans=topoSort(numCourses, prerequisites);
        if(ans.size()==numCourses) return ans;
        return {};
    }
};