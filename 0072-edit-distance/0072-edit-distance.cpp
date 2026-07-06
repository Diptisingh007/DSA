class Solution {
public:
//    int solve(int n, int m, string &s1, string &s2,vector<vector<int>> &dp){
//         if(n==0) return m;
//         if(m==0) return n;
//           if(dp[n][m]!=-1) return dp[n][m];
//         if(s1[n-1]==s2[m-1]){
//             return dp[n][m]= 0+solve(n-1,m-1,s1,s2,dp);
//         }
//         return  dp[n][m]= min(1+solve(n,m-1,s1,s2,dp),min(1+solve(n-1,m,s1,s2,dp),1+solve(n-1,m-1,s1,s2,dp)));
//    }
//     int minDistance(string word1, string word2) {
//         int n=word1.size();
//         int m=word2.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//         return  solve(n,m,word1,word2,dp);
//     }


    int minDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int i=0;i<=m;i++) dp[0][i]=i;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min(1+dp[i-1][j],min(1+dp[i][j-1],1+dp[i-1][j-1]));
                }
            }
        }
        return  dp[n][m];
    }
};