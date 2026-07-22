class Solution {
public:
   bool palindrome(int i,int j, string &s){

    while(i<j){
        if(s[i]!=s[j]) return false;
        i++,j--;
    }
    return true;
   }
    int solve(int i, string &s,vector<int> &dp){
        int n=s.size();
         if(i==n) return 0;    
         
         if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX;
           
        for(int j=i;j<n;j++){
            if(palindrome(i,j,s)){
               int  cost=1+solve(j+1,s,dp);
               mini=min(mini,cost);
            }
        }

        return dp[i]=mini;
    }
    // int minCut(string s) {
    //     int n= s.size();
    //     vector<int> dp(n,-1);
    //    return solve(0,s,dp)-1;

    // }
    int minCut(string s) {
        int n= s.size();
        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            int mini=INT_MAX;
           
            for(int j=i;j<n;j++){
                if(palindrome(i,j,s)){
                   int  cost=1+dp[j+1];
                   mini=min(mini,cost);
                }
            }
            dp[i]=mini;
        }
       return dp[0]-1;

    }
};