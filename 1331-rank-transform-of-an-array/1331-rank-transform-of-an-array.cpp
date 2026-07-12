class Solution {
public:
    // vector<int> arrayRankTransform(vector<int>& arr) {
    //     int n=arr.size();
    //     unordered_map<int,int> mpp;
    //     vector<int> nums=arr;
    //     sort(nums.begin(),nums.end());
    //     int rank=1;
    //     for(int i=0;i<n;i++){
    //         if(mpp.find(nums[i])==mpp.end()){
    //             mpp[nums[i]]=rank++;
    //         }
    //     }
         
    //     for(int i=0;i<n;i++){
    //         nums[i]=mpp[arr[i]];
    //     }

    //     return nums;
    // }


    vector<int> arrayRankTransform(vector<int>& arr){
        int n=arr.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({arr[i],i});
        }

        vector<int> ans(n);
        int rank=1;

        while(!pq.empty()){
            auto it=pq.top();
            int val=it.first;
            int index=it.second;

            ans[index]=rank;

            while(!pq.empty() && pq.top().first==val){
                ans[pq.top().second]=rank;
                pq.pop();
            }
            rank++;
        }

        return ans;
    }
};