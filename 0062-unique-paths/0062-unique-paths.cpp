class Solution {
public:
    // int solve(int i, int j,vector<vector<int>> &dp){
    //     if(i==0 || j==0) return 1;
         
    //      if(dp[i][j]!=-1) return dp[i][j];
    //     int left=solve(i,j-1,dp);
    //     int up=solve(i-1,j,dp);

    //     int sum=left+up;
    //     return dp[i][j]=sum;
    // }
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m,vector<int>(n,-1));
    //     return solve(m-1,n-1,dp);
    // }


    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m,vector<int>(n,1));
    //     for(int i=1;i<m;i++){
    //         for(int j=1;j<n;j++){
    //             dp[i][j]=dp[i-1][j]+dp[i][j-1];
    //         }
    //     }

    //     return dp[m-1][n-1];
    // }

    int uniquePaths(int m, int n){
        vector<int> prev(n,1);
        for(int j=1;j<m;j++){
            for(int i=1;i<n;i++){
               prev[i]=prev[i-1]+prev[i];
            }
        }
        return prev[n-1];
    }
};