class Solution {
public:
   void solve(int r,int c,vector<vector<int>>& image,vector<vector<int>>& ans,int init_col,int color){
     int n=image.size();
     int m=image[0].size();
      ans[r][c]=color;

      int dr[4]={0,0,-1,+1};
      int dc[4]={+1,-1,0,0};

      for(int i=0;i<4;i++){
        int newr=r+dr[i];
        int newc=c+dc[i];

        if(newr>=0 && newc>=0 && newr<n && newc<m && image[newr][newc]==init_col && ans[newr][newc]!=color){
            solve(newr,newc,image,ans,init_col,color);
        }
      }
   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int init_col=image[sr][sc];
        vector<vector<int>> ans=image;
          solve(sr,sc,image,ans,init_col,color);
        return ans;  
    }
};