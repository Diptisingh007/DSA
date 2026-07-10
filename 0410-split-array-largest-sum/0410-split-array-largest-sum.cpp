class Solution {
public:
    bool solve(vector<int> &nums, int k, long long mid){
        int n=nums.size();
        int cnt=1;
        long long sum=0;
        for(int i=0;i<n;i++){
            if(sum+nums[i]>mid){
                cnt++;
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
        }

        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        long long low=*max_element(nums.begin(),nums.end());
        long long high=accumulate(nums.begin(),nums.end(),0LL);

        int ans=high;

        while(low<=high){
            long long mid=low+(high-low)/2;
            if(solve(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};