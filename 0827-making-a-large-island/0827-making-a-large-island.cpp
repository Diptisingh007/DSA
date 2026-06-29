class Disjointset{
    public:
    vector<int> parent,rank,size;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        Disjointset ds(n*n);
        int dr[4]={0,0,-1,+1};
        int dc[4]={-1,+1,0,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                int node=(i*n)+j;
                for(int k=0;k<4;k++){
                    int newr=i+dr[k];
                    int newc=j+dc[k];

                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                       int adjNode=(newr*n)+newc;
                       ds.UnionBySize(node,adjNode);
                    }
                }
            }
        }

        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                set<int> st;
                if(grid[i][j]==1) continue;
                int node=(i*n)+j;
                for(int k=0;k<4;k++){
                    int newr=i+dr[k];
                    int newc=j+dc[k];

                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                       int adjNode=(newr*n)+newc;
                       st.insert(ds.findUPar(adjNode));
                    }
                }

                int cnt=0;
                for(auto &it: st){
                    cnt+=ds.size[it];
                }
                    maxi=max(maxi,cnt+1);
            }
        }
        for(int i=0;i<n*n;i++){
            maxi=max(maxi,ds.size[ds.findUPar(i)]);
        }

        return maxi;
    }
};