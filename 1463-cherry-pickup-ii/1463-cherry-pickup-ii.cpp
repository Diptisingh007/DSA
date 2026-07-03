class Solution {
public:
    int dp[71][101][101];
    // int solve(int i, int j1, int j2, vector<vector<int>>& grid){
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     if(j1<0 || j2<0 || j1>=m || j2>=m) return -1e9;
    //     if(i==n-1){
    //         if(j1==j2) return grid[i][j1];
    //         return grid[i][j1]+grid[i][j2];
    //     }

    //     if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

    //     int maxi=0;
    //     for(int dr=-1;dr<=1;dr++){
    //         for(int dc=-1;dc<=1;dc++){
    //             if(j1==j2){
    //                 maxi=max(maxi,grid[i][j1]+solve(i+1,j1+dr,j2+dc,grid));
    //             }
    //             else{
    //                 maxi=max(maxi,grid[i][j1]+grid[i][j2]+solve(i+1,j1+dr,j2+dc,grid));
    //             }
    //         }
    //     }

    //     return  dp[i][j1][j2]=maxi;
    // }
    // int cherryPickup(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     memset(dp, -1, sizeof(dp));
    //     return solve(0,0,m-1,grid);
    // }


    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        memset(dp, 0, sizeof(dp));

        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
               if(j1==j2) dp[n-1][j1][j2]=grid[n-1][j1];
               else dp[n-1][j1][j2]=grid[n-1][j1] + grid[n-1][j2];
            }
        }

        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
               for(int j2=0;j2<m;j2++){
                    int maxi=-1e9;
                    for(int dr=-1;dr<=1;dr++){
                        for(int dc=-1;dc<=1;dc++){
                            int value=0;
                            if(j1==j2) value=grid[i][j1];
                            else value= grid[i][j1]+grid[i][j2];
                            if( j1+dr>=0 && j2+dc>=0 && j1+dr<m && j2+dc<m)
                                value+=dp[i+1][j1+dr][j2+dc];
                            else 
                                 value+=-1e9;

                            maxi=max(maxi,value);
                        }
                    }

                    dp[i][j1][j2]=maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }



};