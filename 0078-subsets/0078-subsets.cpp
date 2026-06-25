class Solution {
public:
    // void solve(int ind, vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums){
    //     int n=nums.size();
    //     // if(ind==n){
    //         ans.push_back(ds);
    //         // return;
    //     // }

    //     // ds.push_back(nums[ind]);
    //     // solve(ind+1,ans,ds,nums);
    //     // ds.pop_back();
    //     // solve(ind+1,ans,ds,nums);


    //      for(int i=ind;i<n;i++){
    //         // if(i!=ind && nums[i]==nums[i-1]) continue;
    //         ds.push_back(nums[i]);
    //         solve(i+1,ans,ds,nums);
    //         ds.pop_back();
    //     }

    // }
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     vector<int> ds;
    //     solve(0,ans,ds,nums);
    //     return ans;
    // }




    vector<vector<int>> subsets(vector<int>& nums){
        int n=nums.size();
         vector<vector<int>> ans;
         int subsets=pow(2,n);
         for(int i=0;i<subsets;i++){
            vector<int> ds;
             for(int k=0;k<n;k++){
                if(i&(1<<k)){
                    ds.push_back(nums[k]);
                }
             }
             ans.push_back(ds);
         }
         return ans;
    }
};