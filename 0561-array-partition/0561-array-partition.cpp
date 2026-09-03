class Solution {
public:
    // int arrayPairSum(vector<int>& nums) {
    //     int n=nums.size();
    //     sort(nums.begin(),nums.end());
    //     int max=0;
    //     int i=0;
    //     int j=1;
    //     while(i<n){
    //         int mini =min(nums[i],nums[j]);
    //         max=mini+max;
    //         i=i+2;
    //         j=j+2;
    //     }
    //     return max;
    // }


    int arrayPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i+=2){
            ans+=nums[i];
        }
        return ans;
    }
};