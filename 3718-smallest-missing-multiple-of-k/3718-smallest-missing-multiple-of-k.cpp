class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(auto &it:nums) mpp[it]++;
        int p=k;
        while(true){
            if(mpp.find(k)==mpp.end()) return k;
            k=k+p;
        }

        return k;
    }
};