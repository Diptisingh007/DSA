class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int ans=0;
        map<int,int> mpp;
        while(r<n){
            mpp[nums[r]]++;
            if(l<r && mpp.size()>2){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }

            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};