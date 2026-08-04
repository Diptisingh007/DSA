class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& nums) {
        int n=nums.size();
        map<pair<int,int>,int> mpp;
        for(int i=0;i<n;i++){
            int a=min(nums[i][0],nums[i][1]);
            int b=max(nums[i][0],nums[i][1]);
            mpp[{a,b}]++;
        }

        int ans=0;
        for(auto &it: mpp){
            int f=it.second;
            ans=ans+(f*(f-1))/2;
        }

        return ans;
    }
};