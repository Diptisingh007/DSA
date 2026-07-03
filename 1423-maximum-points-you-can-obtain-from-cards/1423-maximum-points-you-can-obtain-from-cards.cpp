class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;

        int leftsum=0;
        for(int i=0;i<k;i++) leftsum+=nums[i];

        ans=max(ans,leftsum);
        int rightsum=0;
        int r=k-1;
        for(int i=n-1;i>=n-k;i--){
           leftsum=leftsum-nums[r];
           rightsum=rightsum+nums[i];
           ans=max(ans,leftsum+rightsum);
           r--;
        }

        return ans;
    }
};