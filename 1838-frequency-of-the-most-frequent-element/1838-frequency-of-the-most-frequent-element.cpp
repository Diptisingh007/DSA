class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());

        long long sum = 0;
        int i = 0, ans = 1;

        for (int j = 0; j < n; j++) {
            sum += nums[j];

            while ((long long)nums[j] * (j - i + 1) - sum > k) {
                sum -= nums[i];
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};