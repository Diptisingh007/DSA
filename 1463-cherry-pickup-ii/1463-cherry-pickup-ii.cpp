class Solution {
public:
    int dp[71][101][101];
    int solve(int i, int j1, int j2, vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(j1<0 || j2<0 || j1>=m || j2>=m) return -1e9;
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            return grid[i][j1]+grid[i][j2];
        }

        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

        int maxi=0;
        for(int dr=-1;dr<=1;dr++){
            for(int dc=-1;dc<=1;dc++){
                if(j1==j2){
                    maxi=max(maxi,grid[i][j1]+solve(i+1,j1+dr,j2+dc,grid));
                }
                else{
                    maxi=max(maxi,grid[i][j1]+grid[i][j2]+solve(i+1,j1+dr,j2+dc,grid));
                }
            }
        }

        return  dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0,0,m-1,grid);
    }
};