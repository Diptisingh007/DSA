class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int a = 0;
        bool not_zero=true;
        for(int i=0;i<n;i++){
            a=a^nums[i];
            if(a!=0) not_zero=false;
        }

        if(not_zero==true) return 0;

        if(a==0) return n-1;
        return n;
    }
};