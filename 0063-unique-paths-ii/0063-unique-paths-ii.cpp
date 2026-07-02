class Solution {
public:
    int solve(int i, int j,vector<vector<int>>& nums,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(nums[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int left=solve(i,j-1,nums,dp);
        int up=solve(i-1,j,nums,dp);

        return dp[i][j]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,nums,dp);
    }
};