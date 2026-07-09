class Solution {
public:
    bool solve(vector<int> &nums,int days, int mid){
        int n=nums.size();
        int cnt=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>mid){
                cnt++;
                sum=nums[i];
            }
        }

        return cnt<=days;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=high;

        while(low<=high){
            int mid=high-(high-low)/2;
            
            if(solve(nums,days,mid)){
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