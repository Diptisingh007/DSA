class Solution {
public:
    // int solve(vector<int> &nums){
    //     int n=nums.size();
    //     int cnt=0;
    //     int ele=0;

    //     for(int i=0;i<n;i++){
    //         if(cnt==0){
    //             ele=nums[i];
    //             cnt++;
    //         }
    //         else if(nums[i]==ele){
    //             cnt++;
    //         }
    //         else{
    //             cnt--;
    //         }
    //     }

    //     cnt=0;
    //     for(int i=0;i<n;i++){
    //         if(nums[i]==ele){
    //             cnt++;
    //         }
    //     }

    //     if(cnt>n/2) return ele;
    //     return -1;
    // }
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=0;
        
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<n;j++){
                if(nums[j]==target){
                    cnt++;
                }
                int len=j-i+1;
                if(cnt>len/2){
                    ans++;
                }
            }
        }

        return ans;
    }
};