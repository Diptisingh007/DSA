class Solution {
public:
    int solve(vector<int>& nums,int ind, int target,vector<int> &dp){
        int n=nums.size();
        if(ind==n-1) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans=INT_MIN;
        
        for(int i=ind+1;i<n;i++){
            if(abs(nums[i]-nums[ind])<=target){
                int cnt=solve(nums,i,target,dp);
                if(cnt!=INT_MIN) ans=max(ans,1+cnt);
            }
        }
        return dp[ind]=ans;;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(n,-1);
        int ans=solve(nums,0,target,dp);
        if(ans==INT_MIN) return -1;
        return ans;
    }
};