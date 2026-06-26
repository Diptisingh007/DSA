class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        long long cumsum=0;
        long long validleftsum=0;
        long long ans=0;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
               validleftsum+=mpp[cumsum];
               cumsum+=1;
            }
            else{
               cumsum-=1;
               validleftsum-=mpp[cumsum];
            }

            mpp[cumsum]+=1;
            ans+=validleftsum;
        }
        return ans;
    }
};