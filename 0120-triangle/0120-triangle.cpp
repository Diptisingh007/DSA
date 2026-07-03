class Solution {
public:
    // int solve(int i, int j,vector<vector<int>>& arr,vector<vector<int>>& dp){
    //     int n= arr.size();
    //     if(i==n-1) return arr[i][j];

    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int a= arr[i][j] + solve(i+1,j,arr,dp);
    //     int b= arr[i][j] + solve(i+1,j+1,arr,dp);

    //     return dp[i][j]= min(a,b);

    // }
    // int minimumTotal(vector<vector<int>>& arr) {
    //     int n= arr.size();
    //     vector<vector<int>> dp(n,vector<int>(n,-1));
    //     return solve(0,0,arr,dp);
    // }

    // int minimumTotal(vector<vector<int>>& arr) {
    //     int n= arr.size();
    //     vector<vector<int>> dp(n,vector<int>(n,0));
    //     for(int j=0;j<n;j++){
    //         dp[n-1][j]=arr[n-1][j];
    //     }

    //     for(int i=n-2;i>=0;i--){
    //         for(int j=0;j<=i;j++){
    //             dp[i][j]=arr[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
    //         }
    //     }
    //     return dp[0][0];
    // }


    int minimumTotal(vector<vector<int>>& arr) {
        int n= arr.size();
        vector<int> dp(n,0);
        for(int j=0;j<n;j++){
            dp[j]=arr[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[j]=arr[i][j] + min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
    }
};