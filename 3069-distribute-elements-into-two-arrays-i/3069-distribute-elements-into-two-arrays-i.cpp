class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans1;
        vector<int> ans2;
    
        int i=0,j=1;
        while(i<n && j<n){
            if(nums[i]>nums[j]){
                ans1.push_back(nums[i]);
                i=max(i,j)+1;
            }
            else{
                ans2.push_back(nums[j]);
                j=max(i,j)+1;
            }
        }
        if(i==n) ans2.push_back(nums[j]);
        if(j==n) ans1.push_back(nums[i]);

        vector<int> ans;
        for(int i=0;i<ans1.size();i++) ans.push_back(ans1[i]);
        for(int i=0;i<ans2.size();i++) ans.push_back(ans2[i]);

        return ans;
    }
};