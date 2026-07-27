class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,h=n-1;
        while(l<h){
            int sum=nums[l]+nums[h];
            if(sum==target) return {l+1,h+1};
            if(sum>target) h--;
            else l++;
        }

        return {-1,-1};
    }
};