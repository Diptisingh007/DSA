class Disjointset{
  public:
    vector<int> parent,rank,size;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        Disjointset ds(n*n);
        
        int dr[4]={-1,+1,0,0};
        int dc[4]={0,0,-1,+1};

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                int node=i*n+j;
                for(int k=0;k<4;k++){
                    int newr=i+dr[k];
                    int newc=j+dc[k];
                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                        int adjnode=newr*n+newc;
                        ds.UnionS(node,adjnode);
                    }
                }
            }
        }

        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                int node=i*n+j;
                set<int> st;
                for(int k=0;k<4;k++){
                    int newr=i+dr[k];
                    int newc=j+dc[k];
                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                        int adjnode=newr*n+newc;
                        st.insert(ds.findUPar(adjnode));
                    }
                }

                int cnt=0;
                for(auto &it: st){
                    cnt+=ds.size[it];
                }
                maxi=max(maxi,cnt+1);
            }
        }
        
        int ans=0;
        for(int i=0;i<n*n;i++){
            ans=max(maxi,ds.size[ds.findUPar(i)]);
        }

        return ans;
    }
};