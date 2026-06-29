class Disjointset{
    vector<int> parent,rank,size;
    public:
    Disjointset(int n){
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        size.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
     
    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUPar(parent[node]);
    }
    
    void UnionByRank(int u, int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void UnionBySize(int u, int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        
        if(ulp_u==ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& nums) {

        Disjointset ds(n);
        int edge_extra=0;
        for(auto &it: nums){
            int u=it[0];
            int v=it[1];

            if(ds.findUPar(u)==ds.findUPar(v)){
                edge_extra++;
            }
            else {
                ds.UnionBySize(u,v);
            }
        }

        int components=0;
        for(int i=0;i<n;i++){
            if(ds.findUPar(i)==i) components++;
        }

        int edge_needed=components-1;

        if(edge_needed<=edge_extra){
            return edge_needed;
        }
        return -1;
    }
};