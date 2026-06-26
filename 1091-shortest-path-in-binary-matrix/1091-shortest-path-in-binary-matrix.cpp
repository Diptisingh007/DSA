class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0]=1;
        q.push({0,0});

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second;
            int dis=dist[r][c];
            
            if(r==n-1 && c==n-1) return dis;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int newr=r+i;
                    int newc=c+j;

                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==0){
                        if(dis+1 < dist[newr][newc]){
                            dist[newr][newc]=dis+1;
                            q.push({newr,newc});
                        }
                    }
                }
            }
        }

        return -1;
    }
};