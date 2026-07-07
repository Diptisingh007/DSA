class Solution {
public:
    // int solve(int ind, int buy, vector<int>& nums,vector<vector<int>> &dp){
    //     int n = nums.size();

    //     if(ind == n) return 0;
    //     if(dp[ind][buy]!=-1) return dp[ind][buy];

    //     if(buy){
    //         return dp[ind][buy]= max(-nums[ind] + solve(ind+1,0,nums,dp),
    //                    solve(ind+1,1,nums,dp));
    //     }
    //     else{
    //         return dp[ind][buy]=max(nums[ind] + solve(ind+1,1,nums,dp),
    //                    solve(ind+1,0,nums,dp));
    //     }
    // }

    // int maxProfit(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>> dp(n,vector<int>(2,-1));
    //     return solve(0,1,nums,dp);
    // }


    // int maxProfit(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>> dp(n+1,vector<int>(2,0));

    //         for(int i=n-1;i>=0;i--){
    //             for(int buy=1;buy>=0;buy--){
    //                 if(buy){
    //                    dp[i][buy]=max((-nums[i]+dp[i+1][0]),(0+dp[i+1][1]));
    //                 }
    //                 else{
    //                    dp[i][buy]=max((nums[i]+dp[i+1][1]),(0+dp[i+1][0]));
    //                 }
    //             }
    //         }
    //     return dp[0][1];;
    // }
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        vector<int> ahead(2,0);
        vector<int> curr(2,0);

            for(int i=n-1;i>=0;i--){
                for(int buy=1;buy>=0;buy--){
                    if(buy){
                       curr[buy]=max((-nums[i]+ahead[0]),(0+ahead[1]));
                    }
                    else{
                       curr[buy]=max((nums[i]+ahead[1]),(0+ahead[0]));
                    }
                }
                ahead=curr;
            }
        return ahead[1];;
    }
};