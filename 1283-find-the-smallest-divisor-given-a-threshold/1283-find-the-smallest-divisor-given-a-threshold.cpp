class Solution {
public:
    bool solve(vector<int>&nums, int t,int mid){
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
           cnt+=(nums[i]+mid-1)/mid;
        }
        if(cnt<=t) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int high=*max_element(nums.begin(),nums.end());

        int ans=high;

        while(low<=high){
            int mid=high-(high-low)/2;

            if(solve(nums,threshold,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};