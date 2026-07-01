class Solution {
public:
     int solve(vector<int>& nums) {
        int n=nums.size();
        // vector<int> dp(n+1,0);
        int prev1=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){

            int take=nums[i];
            if(i>=2) take=nums[i]+prev2;
            int notake=0+prev1;

            int curr=max(take,notake);
            prev2=prev1;
            prev1=curr;
        }

        return prev1;;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp1,temp2;
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }

        int a=solve(temp1);
        int b=solve(temp2);
        return max(a,b);

    }
};