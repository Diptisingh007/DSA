class Solution {
public:
    int solve(int ind, int trans,int k,vector<int>&nums,vector<vector<int>> &dp){
        int n=nums.size();
        if(ind==n || trans==2*k) return 0;
        if(dp[ind][trans]!=-1) return dp[ind][trans];
        if(trans%2==0){
            return dp[ind][trans]= max((-nums[ind]+solve(ind+1,trans+1,k,nums,dp)),0+solve(ind+1,trans,k,nums,dp));
        }
        else 
            return dp[ind][trans]= max((nums[ind]+solve(ind+1,trans+1,k,nums,dp)),0+solve(ind+1,trans,k,nums,dp));
    }
    int maxProfit(int k, vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k,-1));
        return solve(0,0,k,nums,dp);
    }
};