class Solution {
public:
    // int solve(int ind, int prev,vector<int>&nums,vector<vector<int>> &dp){
    //     int n=nums.size();
    //     if(ind==n) return 0;
        
    //     if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

    //     int len=0+solve(ind+1,prev,nums,dp);
    //     if(prev==-1 || nums[ind]>nums[prev]){
    //         len=max(len,1+solve(ind+1,ind,nums,dp));
    //     }

    //     return dp[ind][prev+1]= len;
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    //     return solve(0,-1,nums,dp);
    // }



    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    //     for(int i=n-1;i>=0;i--){
    //         for(int prev=i-1;prev>=-1;prev--){
    //             int len=0+dp[i+1][prev+1];
    //             if(prev==-1 || nums[i]>nums[prev]){
    //                 len=max(len,1+dp[i+1][i+1]);
    //             }
    //             dp[i][prev+1]=len;
    //         }
    //     }
    //     return dp[0][0];
    // }



    // int lengthOfLIS(vector<int>& nums){
    //     int n=nums.size();
    //     vector<int> dp(n,1);
    //     int ans=0;
    //     for(int i=0;i<n;i++){
    //         for(int prev=0;prev<i;prev++){
    //             if(nums[i]>nums[prev]){
    //                 dp[i]=max(dp[i],1+dp[prev]);
    //             }
    //         }
    //         ans=max(ans,dp[i]);
    //     } 
    //     return ans;
    // }
     
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        vector<int> ans;

        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int ind=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[ind]=nums[i];
            }
        }
        return ans.size();
    } 
};