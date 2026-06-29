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
    vector<vector<string>> accountsMerge(vector<vector<string>>& nums) {
        int n=nums.size();
        // int m=nums[0].size();
        Disjointset ds(n);
        unordered_map<string,int> mpp;
        for(int i=0;i<n;i++){
            int m=nums[i].size();
            for(int j=1;j<m;j++){
                string mail=nums[i][j];
                if(!mpp.contains(mail)){
                    mpp[mail]=i;
                }
                else{
                    ds.UnionBySize(i,mpp[mail]);
                }
            }
        }

        vector<vector<string>> merge_mail(n);
        for(auto &it: mpp){
            string mail=it.first;
            int index=it.second;
            int node=ds.findUPar(index);
            merge_mail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(merge_mail[i].size()==0) continue;
            sort(merge_mail[i].begin(),merge_mail[i].end());

            vector<string> temp;
            temp.push_back(nums[i][0]);
            for(auto &it: merge_mail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};