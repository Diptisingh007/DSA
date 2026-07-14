class Disjointset{
        vector<int> parent,rank,size;
  public:
    Disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
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
    
    void UnionR(int u, int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_v]+=1;
        }
    }
    void UnionS(int u, int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else{
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& nums) {
        int n=nums.size();
        int maxrow=0;
        int maxcol=0;
        for(auto &it: nums){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }  

        int totalNode=maxrow+maxcol+1;
        Disjointset ds(totalNode);
        unordered_map<int,int> mpp;
        for(auto &it: nums){
            int row_node=it[0];
            int col_node=it[1]+maxrow+1;
            ds.UnionS(row_node,col_node);
            mpp[row_node]=1;
            mpp[col_node]=1;
        }

        int cnt=0;
        for(auto &it: mpp){
            int node=it.first;
            if(ds.findUPar(node)==node) cnt++;
        }
        
        int ans=n-cnt;
        return ans;
    }
};