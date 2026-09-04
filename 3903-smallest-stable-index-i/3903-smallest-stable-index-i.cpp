class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MAX;
        vector<int> mini(n,INT_MAX);
        mini[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            mini[i]=min(mini[i+1],nums[i]);
        }

        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            int b=mini[i];
            int diff=(maxi-b);
            if(diff<=k){
                // ans=min(ans,i);
                return i;
            }
        }
        
        if(ans==INT_MAX) return -1;
        return ans;
    }
};