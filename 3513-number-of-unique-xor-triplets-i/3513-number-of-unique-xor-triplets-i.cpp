class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;

        int ans=0;
        for(auto &it: nums){
            ans=ans | it;
        }

        return ans+1;
    }
};