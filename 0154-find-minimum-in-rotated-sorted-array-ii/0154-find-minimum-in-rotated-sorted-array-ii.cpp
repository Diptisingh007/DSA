class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        int low=0,high=n-1;
        if(nums[low]<nums[high]) return nums[low];
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                ans=min(nums[low],ans);
                low++,high--;
            }
            else if(nums[low]<=nums[mid]){
                ans=min(nums[low],ans);
                low=mid+1;
            }
            else{
                ans=min(nums[mid],ans);
                high=mid-1;
            }
        }
        return ans;
    }
};