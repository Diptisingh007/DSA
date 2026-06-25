class Solution {
public:
    // vector<int> singleNumber(vector<int>& nums) {
    //     int n=nums.size();
    //     unordered_map<int,int> mpp;
    //     for(auto &it: nums){
    //         mpp[it]++;
    //     }
    //     vector<int> ans;
    //     for(auto &it: mpp){
    //         if(it.second==1){
    //             ans.push_back(it.first);
    //         }
    //     }
    //     return ans;
    // }


    vector<int> singleNumber(vector<int>& nums){
        int n=nums.size();
        long temp=0;
        for(auto &it: nums) temp=temp^it;

        int rightmost=(temp & (temp-1))^temp;
        int b1=0,b2=0;
        for(int i=0;i<n;i++){
             if(nums[i] & rightmost){
                b1=b1^nums[i];
             }
             else{
                b2=b2^nums[i];
             }
        }

        return {b1,b2};
    }
};