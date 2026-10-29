class Solution {
public:
    void solve(int ind,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans,int t){
        int n=nums.size();
        if(t==0){
            ans.push_back(ds);
            return;
        }
        if(ind==n){
            if(t==0){
                ans.push_back(ds);
            }
            return;
        }

        if(nums[ind]<=t){
            ds.push_back(nums[ind]);
            solve(ind,nums,ds,ans,t-nums[ind]);
            ds.pop_back();
        }
        solve(ind+1,nums,ds,ans,t);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,nums,ds,ans,target);
        return ans;
    }
};