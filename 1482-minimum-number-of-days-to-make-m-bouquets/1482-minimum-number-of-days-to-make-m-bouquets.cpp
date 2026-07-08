class Solution {
public:
    bool solve(vector<int>& nums, int m, int k,int mid){
        int n=nums.size();
        int flower=0,ban=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=mid){
                flower++;
                if(flower==k){
                    ban++;
                    flower=0;
                }
            }
            else{
                flower=0;
            }
        }
        if(ban>=m) return true;
        return false;
    }
    int minDays(vector<int>& nums, int m, int k) {
        int n=nums.size();
        if((long long)n<(long long )m*k) return -1;
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());

        int ans=high;

        while(low<=high){
            int mid=high-(high-low)/2;

            if(solve(nums,m,k,mid)){
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