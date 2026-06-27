class Solution {
public:
    int trap(vector<int>& nums){
        int n=nums.size();
        int l=0,r=n-1;
        int left_max=0,right_max=0;
        int ans=0;

        while(l<r){
            if(nums[l]<=nums[r]){
                if(left_max > nums[l]){
                   ans=ans+(left_max-nums[l]);
                }
                else{
                   left_max=nums[l];
                }
                l++;
            }
            else{
                if(right_max > nums[r]){
                   ans=ans+(right_max-nums[r]);
                }
                else{
                   right_max=nums[r];
                }
                r--;
            }
        }

        return ans;
    }
};