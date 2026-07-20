class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        k=k%(n*m);
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ind=i*m+j;
                int new_ind=(ind+k)%(n*m);
                ans[new_ind/m][new_ind%m]=grid[i][j];
            }
        }
        return ans;
    }
};