class Solution {
public:
    void solve(int ind, vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums){
        int n=nums.size();
        ans.push_back(ds);

         for(int i=ind;i<n;i++){
            ds.push_back(nums[i]);
            solve(i+1,ans,ds,nums);
            ds.pop_back();
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,ans,ds,nums);
        return ans;
    }

};