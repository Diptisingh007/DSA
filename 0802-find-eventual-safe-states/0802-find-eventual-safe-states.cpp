class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<vector<int>> adjrev(n);
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto &it : adj[i]){
               adjrev[it].push_back(i);
               indegree[i]++;
            }
        }

        // for(int i=0;i<n;i++){
        //     for(auto &it: adjRev[i]){
        //         indegree[it]++;
        //     }
        // }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
               q.push(i);
            }
        }
       
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);
            for(auto it : adjrev[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
         return ans;
    
    }
};