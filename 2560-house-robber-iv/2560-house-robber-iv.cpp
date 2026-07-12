class Solution {
public:
    bool solve(vector<int> &nums,int k, int mid){
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=mid){
                cnt++;
                i+=1;
            }
        }

        return cnt>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());

        int ans=high;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(solve(nums,k,mid)){
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