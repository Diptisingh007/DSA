class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> nums=board;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ele=nums[i][j];

                int cnt0=0;
                int cnt1=0;
                for(int p=-1;p<=1;p++){
                    for(int q=-1;q<=1;q++){
                        if(p==0 && q==0) continue;
                        int row=i+p;
                        int col=j+q;
                        if( row>=0 && col>=0 && row<n && col<m && board[row][col]==1) cnt1++;
                        if( row>=0 && col>=0 && row<n && col<m && board[row][col]==0) cnt0++;
                    }
                }

                if(ele==1){
                    if(cnt1<2) nums[i][j]=0;
                    if(cnt1==2 || cnt1==3) nums[i][j]=1;
                    if(cnt1>3) nums[i][j]=0;
                }
                else{
                    if(cnt1==3) nums[i][j]=1;
                }
            }
        }

        board=nums;
    }
};