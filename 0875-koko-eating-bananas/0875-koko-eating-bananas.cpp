class Solution {
public:
    bool solve(vector<int> &nums,int h,int mid){
        int n=nums.size();
        long long time=0;
        for(int i=0;i<n;i++){
           time=time+(nums[i]+mid-1)/mid;
           if(time>h) return false;
        }

        return true;
    }
    int minEatingSpeed(vector<int>& nums, int h) {
        int n=nums.size();
        int low=1,high=*max_element(nums.begin(),nums.end());
        int ans=high;

        while(low<=high){
            int mid=high-(high-low)/2;

            if(solve(nums,h,mid)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};