class Solution {
public:
int mod=1e9+7;
    int solve(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> prev(target+1,0);
        vector<int> curr(target+1,0);
        
        prev[0]=1;
        if(arr[0]==0) prev[0]=2;
        if(arr[0]!=0 && arr[0]<=target){
            prev[arr[0]]=1;
        }
        
        for(int i=1;i<n;i++){
            for(int sum=0;sum<=target;sum++){
                int pick=0;
                    if(arr[i] <= sum)
                        pick=prev[sum-arr[i]];
                int notpick=prev[sum];
        
                curr[sum]=(pick+notpick)%mod;
            }
            prev=curr;
        }
        return prev[target];
        
    }
    int countPartitions(vector<int>& arr, int diff) {
        int n=arr.size();
        int total=0;
        for(int i=0;i<n;i++) total+=arr[i];
        if(total < diff) return 0;
        int sum=total-diff;
        if(sum%2==1) return 0;
        return solve(arr,sum/2);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
      return  countPartitions(nums,target);
        
    }
};