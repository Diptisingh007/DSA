class Solution {
public:
    int max_ele(vector<vector<int>>& mat,int mid){
        int n=mat.size();
        int m=mat[0].size();
        int ind=-1;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(maxi<mat[i][mid]){
                maxi=mat[i][mid];
                ind=i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            int ind=max_ele(mat,mid);

            int left=-1,right=-1;
            if(mid-1>=0) left=mat[ind][mid-1];
            if(mid+1<m) right=mat[ind][mid+1];

            if(left<mat[ind][mid] && right<mat[ind][mid]){
                return {ind,mid};
            }
            if(left>mat[ind][mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};