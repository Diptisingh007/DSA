class Solution {
public:
    // int findCenter(vector<vector<int>>& edges) {
    //     int n=edges.size();
    //     int ans=0;
    //     vector<int> center(n+2,0);
    //     for(auto it: edges){
    //         center[it[0]]++;
    //         center[it[1]]++;
    //     }

    //     for(int i=1;i<n+2;i++){
    //         if(center[i]==n){
    //            ans=i;
    //         }
    //     }

    //     return ans;
    // }


    int findCenter(vector<vector<int>>& edges){
        if(edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1]){
            return edges[0][0];
        }
        return edges[0][1];
    }
};