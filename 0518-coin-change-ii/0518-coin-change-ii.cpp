class Solution {
public:
    // int solve(int ind, int T, vector<int> &coins,  vector<vector<int>> &dp){
     
    //  if(ind==0){
    //     return (T%coins[0]==0);
    //  }
     
    //  if(dp[ind][T]!=-1) return dp[ind][T];
    // int notTake=solve(ind-1, T, coins,dp);
    // int take=0;
    // if(coins[ind]<=T){
    //     take=  solve(ind,T-coins[ind],coins,dp);
    // }
      
    //   return dp[ind][T]=take+notTake;


    // }
    // int change(int amount, vector<int>& coins) {
    //     int n=coins.size();
    //     vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    //     return solve(n-1,amount,coins,dp);
    // }
    // int mod=1e9+7;
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int> prev(amount+1,0);
        for(int T=0;T<=amount;T++){
            prev[T]=(T%coins[0]==0);
        }

        for(int ind=1;ind<n;ind++){
            for(int T=0;T<=amount;T++){
                long long  notTake=prev[T];
                long long  take=0;
                if(coins[ind]<=T){
                    take=prev[T-coins[ind]];
                }

                prev[T]=(take+notTake);
            }
        }
        return prev[amount];
    }
};