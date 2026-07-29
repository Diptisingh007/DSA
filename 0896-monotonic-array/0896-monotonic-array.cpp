class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();

        int i=1;
        while(i<n && nums[i]>=nums[i-1]) i++;
        if(i==n) return true;

        i=1;
        while(i<n && nums[i]<=nums[i-1]) i++;
        if(i==n) return true;
       
        return false;
    }
};