class Solution {
public:
    // int solve(int i, int j,vector<vector<int>>& nums,vector<vector<int>> &dp){
    //     if(i<0 || j<0) return 0;
    //     if(nums[i][j]==1) return 0;
    //     if(i==0 && j==0) return 1;
        
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int left=solve(i,j-1,nums,dp);
    //     int up=solve(i-1,j,nums,dp);

    //     return dp[i][j]=left+up;
    // }
    // int uniquePathsWithObstacles(vector<vector<int>>& nums) {
    //     int n=nums.size();
    //     int m=nums[0].size();
    //     vector<vector<int>> dp(n,vector<int>(m,-1));
    //     return solve(n-1,m-1,nums,dp);
    // }




   
    // int uniquePathsWithObstacles(vector<vector<int>>& nums) {
    //     int n=nums.size();
    //     int m=nums[0].size();
    //     vector<vector<int>> dp(n,vector<int>(m,0));

    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(nums[i][j]==1) dp[i][j]=0;
    //             else if(i==0 && j==0) dp[i][j]=1;
    //             else{
    //                 int left=0,up=0;
    //                if(j>0)  left=dp[i][j-1];
    //                if(i>0)  up=dp[i-1][j];
    //                dp[i][j]=left+up;

    //             }
    //         }
    //     }
    //     return dp[n-1][m-1];
    // }





    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        vector<int> prev(m,0);

        for(int i=0;i<n;i++){
           vector<int> curr(m,0);
            for(int j=0;j<m;j++){
                if(nums[i][j]==1) curr[j]=0;
                else if(i==0 && j==0) curr[j]=1;
                else{
                    int left=0,up=0;
                   if(j>0)  left=curr[j-1];
                   if(i>0)  up=prev[j];
                   curr[j]=left+up;
                }
            }
            prev=curr;
        }
        return prev[m-1];
    }




};