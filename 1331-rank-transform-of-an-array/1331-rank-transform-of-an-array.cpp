class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        map<int,int> mpp;
        vector<int> nums=arr;
        sort(nums.begin(),nums.end());
        int rank=1;
        for(int i=0;i<n;i++){
            if(mpp.find(nums[i])==mpp.end()){
                mpp[nums[i]]=rank++;
            }
        }
         
        for(int i=0;i<n;i++){
            nums[i]=mpp[arr[i]];
        }

        return nums;
    }
};