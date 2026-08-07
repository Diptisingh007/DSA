class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        int l=0,r=0;
        int prod=1;
        while(r<n){
            prod=prod*nums[r];
            while(l<=r && prod>(k-1)){
                prod=prod/nums[l];
                l++;
            }
            ans+=(r-l+1);
            r++;
        }

        return ans;
    }
};