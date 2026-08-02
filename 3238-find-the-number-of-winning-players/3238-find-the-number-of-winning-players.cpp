class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& nums) {
        int m=nums.size();
        map<pair<int,int>,int> mpp;
        vector<int> vis(n,0);
        for(auto &it: nums){
            mpp[{it[0],it[1]}]++;
        }

        int ans=0;
        for(auto &it: mpp){
            pair<int,int> node=it.first;
            int freq=it.second;
            if(freq>node.first && vis[node.first]==0){
                ans++;
                vis[node.first]=1;
            }
        }
        return ans;
    }
};