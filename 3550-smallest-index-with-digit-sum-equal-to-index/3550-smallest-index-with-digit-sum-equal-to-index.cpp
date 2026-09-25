class Solution {
public:
    int sum(int n){
        int ans=0;
        while(n){
            ans+=(n%10);
            n=n/10;
        }
        return ans;
    }

    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            int s=sum(nums[i]);
            if(s==i){
                ans=i;
                break;
            }
        }

        return ans;

    }
};