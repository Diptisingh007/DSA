class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),[](auto &a, auto &b){
              return a[1]<b[1];
        });
        int ans=1;
        int last=nums[0][1];
        for(int i=1;i<n;i++){
            if(nums[i][0]>last){
                ans++;
                last=nums[i][1];
            }
        }

        return ans;
    }
};