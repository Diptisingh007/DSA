class Solution {
public:
    bool solve(int n, string &s, int m, string &p,vector<vector<int>> &dp){
        if(n==0 && m==0) return true;
        if(n>0 && m==0) return false;
        if(n==0 && m>0){
            for(int i=1;i<=m;i++){
                if(p[i-1]!='*') return false;
            }
            return true;
        }
        if(dp[n][m]!=-1) return dp[n][m];

        if(s[n-1]==p[m-1] || p[m-1]=='?'){
            return dp[n][m]= solve(n-1,s,m-1,p,dp);
        }
        if(p[m-1]=='*'){
            return dp[n][m]= solve(n,s,m-1,p,dp) || solve(n-1,s,m,p,dp);
        }

        return dp[n][m]= false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n,s,m,p,dp);
    }
};