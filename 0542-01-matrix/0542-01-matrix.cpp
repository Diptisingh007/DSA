class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        
        int dr[4]={0,0,1,-1};
        int dc[4]={1,-1,0,0};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first.first;
            int col=it.first.second;
            int step=it.second;
            dis[row][col]=step;

            for(int i=0;i<4;i++){
                int newr=row+dr[i];
                int newc=col+dc[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && vis[newr][newc]==0){
                    q.push({{newr,newc},step+1});
                    vis[newr][newc]=1;
                }
            }
        }

        return dis;
    }
};