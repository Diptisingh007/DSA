class Solution {
public:
    // int solve(int ind,vector<int> &nums, int sum,vector<vector<int>> &dp){
    //     int n=nums.size();
    //     if(sum==0) return 0;
    //     if(ind==0){
    //        if(sum%nums[ind]==0) return sum/nums[ind];
    //        else return 1e9; 
    //     }

    //     if(dp[ind][sum]!=-1) return dp[ind][sum];

    //     int pick=INT_MAX;
    //     if(nums[ind]<=sum){
    //         pick=1+solve(ind,nums,sum-nums[ind],dp);
    //     }
    //     int notpick=0+solve(ind-1,nums,sum,dp);

    //     return  dp[ind][sum]=min(pick,notpick);
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int n=coins.size();
    //     vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    //     int ans= solve(n-1,coins,amount,dp);
    //     if(ans>=1e9) return -1;
    //     return ans;
    // }


    int coinChange(vector<int>& nums, int amount) {

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));

        for (int sum = 0; sum <= amount; sum++) {
            if (sum % nums[0] == 0)
                dp[0][sum] = sum / nums[0];
        }

        for (int ind = 1; ind < n; ind++) {
            for (int sum = 0; sum <= amount; sum++) {

                int notPick = dp[ind - 1][sum];

                int pick = 1e9;
                if (nums[ind] <= sum)
                    pick = 1 + dp[ind][sum - nums[ind]];

                dp[ind][sum] = min(pick, notPick);
            }
        }

        int ans = dp[n - 1][amount];

        return (ans >= 1e9) ? -1 : ans;
    }
};
