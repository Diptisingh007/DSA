class Solution {
public:
    int solve(vector<int> &nums,int x,int y){
        int n=nums.size();
        vector<int> first(n,0),second(n,0);
        int sum=0;

        for(int i=0;i<n;i++){
            if(i<x){
                sum=sum+nums[i];
                first[i]=sum;
            }
            else{
                sum=sum+nums[i]-nums[i-x];
                first[i]=max(sum,first[i-1]);
            }
        }

        sum=0;
        for(int i=n-1;i>=0;i--){
            if(i+y>n-1){
                sum=sum+nums[i];
                second[i]=sum;
            }
            else{
                sum=sum+nums[i]-nums[i+y];
                second[i]=max(second[i+1],sum);
            }
        }

        int ans=INT_MIN;
        for(int i=x-1;i<n-y;i++){
            ans=max(ans,first[i]+second[i+1]);
        }

        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(solve(nums,firstLen,secondLen),solve(nums,secondLen,firstLen));
    }
};