class Solution {
public:
    int solve(int i, int j, vector<int>&nums,vector<vector<int>> &dp){
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j;k++){
            int cost=nums[j+1]-nums[i-1]+solve(i,k-1,nums,dp)+solve(k+1,j,nums,dp);
            ans=min(ans,cost);
        }

        return dp[i][j]= ans;
    }
    int minCost(int n, vector<int>& nums) {
        int m=nums.size();
        nums.push_back(n);
        nums.insert(nums.begin(),0);
        sort(nums.begin(),nums.end());

        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        return solve(1,m,nums,dp);
    }
};