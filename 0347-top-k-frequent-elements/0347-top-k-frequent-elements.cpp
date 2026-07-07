class Solution {
public:
    typedef pair<int ,int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(auto &it: nums) mpp[it]++;

        priority_queue<p,vector<p>,greater<p>> pq;
        vector<int> ans;
        for(auto &it: mpp){
            pq.push({it.second,it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            ans.push_back(it.second);
        }

        return ans;


    }
};