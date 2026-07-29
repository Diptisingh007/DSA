class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int sum = 0;
        int mini = nums[0];
        int minSum = 0;
        int total = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            maxi = max(maxi, sum);
            if (sum < 0)
                sum = 0;

            minSum += nums[i];
            mini = min(mini, minSum);
            if (minSum > 0)
                minSum = 0;

            total += nums[i];
        }

        if (maxi < 0)
            return maxi;

        return max(maxi, total - mini);
    }
};