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
    vector<vector<string>> accountsMerge(vector<vector<string>>& nums) {
        int n=nums.size();
        Disjointset ds(n);
        unordered_map<string , int> mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<nums[i].size();j++){
                string mail=nums[i][j];
                if(!mpp.contains(mail)){
                    mpp[mail]=i;
                }
                else{
                    ds.UnionR(i,mpp[mail]);
                }
            }
        }

        vector<vector<string>> temp(n);
        for(auto &it: mpp){
            string mail=it.first;
            int ind=it.second;
            int node=ds.findUPar(ind);
            temp[node].push_back(mail);

        }


        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(temp[i].size()==0) continue;

            sort(temp[i].begin(),temp[i].end());

            vector<string> res;
            res.push_back(nums[i][0]);
            for(int j=0;j<temp[i].size();j++){
                res.push_back(temp[i][j]);
            }
            ans.push_back(res);
        }

        return ans;
    }
};