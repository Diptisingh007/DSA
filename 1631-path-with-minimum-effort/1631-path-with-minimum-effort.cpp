class Solution {
    typedef pair<int,pair<int,int>> p;
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        priority_queue<p,vector<p>,greater<p>> pq;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});

        int dr[4]={0,0,-1,+1};
        int dc[4]={-1,+1,0,0};

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int e=it.first;
            int r=it.second.first;
            int c=it.second.second;

            for(int i=0;i<4;i++){
                int newr=r+dr[i];
                int newc=c+dc[i];

                if(newr>=0 && newc>=0 && newr<n && newc<m){
                    int newe=max(abs(heights[newr][newc]-heights[r][c]),e);
                    if(newe < dist[newr][newc]){
                        dist[newr][newc]=newe;
                        pq.push({newe,{newr,newc}});
                    }
                }
            }
        }


        if(dist[n-1][m-1]==1e9) return 0;
        return dist[n-1][m-1];
    }
};