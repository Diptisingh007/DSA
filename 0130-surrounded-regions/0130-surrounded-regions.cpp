class Solution {
public:
    void dfs(int row, int col,vector<vector<char>>& board,vector<vector<int>>& vis){
        int n=board.size();
        int m=board[0].size();
        vis[row][col]=1;

        int dr[4]={0,0,+1,-1};
        int dc[4]={+1,-1,0,0};

        for(int i=0;i<4;i++){
            int newr=row+dr[i];
            int newc=col+dc[i];

            if(newr>=0 && newr<n && newc>=0 && newc<m && vis[newr][newc]==0 && board[newr][newc]=='O'){
                dfs(newr,newc,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,board,vis);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,board,vis);
            }
        }
        for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(0,i,board,vis);
            }
            if(!vis[n-1][i] && board[n-1][i]=='O'){
                dfs(n-1,i,board,vis);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }

    }
};