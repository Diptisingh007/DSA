class Solution {
public:
    void solve(int ind, vector<int> &nums,vector<vector<int>> &ans){
        int n=nums.size();
        if(ind>=n){
            ans.push_back(nums);
            return;
        }
        
        unordered_map<int,int> mpp;
        for(int i=ind;i<n;i++){
            if(mpp.find(nums[i])!=mpp.end()) continue;
            mpp[nums[i]]=1;
            swap(nums[i],nums[ind]);
            solve(ind+1,nums,ans);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        solve(0,nums,ans);
        return ans;
    }
};