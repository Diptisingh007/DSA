class Solution {
public:
    void solve(int ind, vector<vector<int>> &ans, vector<int> &nums){
        int n=nums.size();
        if(ind>=n){
            ans.push_back(nums);
        }

        for(int i=ind;i<n;i++){
            swap(nums[i],nums[ind]);
            solve(ind+1,ans,nums);
            swap(nums[i],nums[ind]);
        }
    }

     vector<vector<int>> permute(vector<int>& nums){
        int n=nums.size();
        vector<vector<int>> ans;
        solve(0,ans,nums);
        return ans;
     }
};