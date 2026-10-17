class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mpp;
        int pre=0;
        int ans=0;
        for(int i=0;i<n;i++){
           pre+=nums[i];
           if(pre==k) ans++;
           int rem=pre-k;
           ans=ans+mpp[rem];
           mpp[pre]++;
        }
        return ans;
    }

};