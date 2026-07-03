class Solution {
public:
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<int> prev(sum+1,0);
        vector<int> curr(sum+1,0);
        prev[0]=1;
        if(arr[0]<=sum) prev[arr[0]]=1;
        curr[0]=1;
        
        for(int i=1;i<n;i++){
            for(int tar=1;tar<=sum;tar++){
                bool notpick=prev[tar];
                bool pick=false;
                    if(arr[i]<=tar){
                        pick=prev[tar-arr[i]];
                    }
                curr[tar]=pick || notpick;    
            }
            prev=curr;
        }
        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum%2==1) return false;
        return isSubsetSum(nums,sum/2);
    }
};