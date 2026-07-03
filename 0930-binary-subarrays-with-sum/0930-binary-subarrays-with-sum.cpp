class Solution {
public:
    int solve(vector<int>& nums, int goal){
        int n=nums.size();
        int l=0,r=0;
        int sum=0;
        int ans=0;

        while(r<n){
            sum=sum+nums[r];
            while(l<=r && sum>goal){
                sum=sum-nums[l];
                l++;
            }

            ans=ans+(r-l+1);
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return solve(nums,goal)-solve(nums,goal-1);
    }
};