class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        vector<int> pre;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            int temp=gcd(nums[i],maxi);
            pre.push_back(temp);
        }
        
        int m=pre.size();
        sort(pre.begin(),pre.end());
        long long ans=0;
        int i=0,j=m-1;
        while(i<j){
            ans+=gcd(pre[i],pre[j]);
            i++,j--;
        }

        return ans;
    }
};