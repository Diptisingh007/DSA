class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        int n=arr.size();
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>> p;

        for(int i=0;i<n;i++){
            int dist=arr[i][0]*arr[i][0]+arr[i][1]*arr[i][1];
            p.push({dist,{arr[i][0],arr[i][1]}});

            if(p.size()>k) p.pop();
        }

        while(p.size()>0){
             ans.push_back({p.top().second.first,p.top().second.second});
             p.pop();
        }

        return ans;
    }
};