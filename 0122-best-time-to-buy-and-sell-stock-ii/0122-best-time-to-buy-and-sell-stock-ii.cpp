class Solution {
public:
    int solve(int ind, int buy, vector<int>& nums,vector<vector<int>> &dp){
        int n = nums.size();

        if(ind == n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];

        if(buy){
            return dp[ind][buy]= max(-nums[ind] + solve(ind+1,0,nums,dp),
                       solve(ind+1,1,nums,dp));
        }
        else{
            return dp[ind][buy]=max(nums[ind] + solve(ind+1,1,nums,dp),
                       solve(ind+1,0,nums,dp));
        }
    }

    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,nums,dp);
    }
};