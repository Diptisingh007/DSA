class Solution {
public:
    long long mod = 1e9 + 7;

    long long solve(long long val, long long power) {
        long long ans = 1;

        while (power) {
            if (power % 2 == 1) {
                ans = (ans * val) % mod;
            }

            val = ((val%mod) * (val%mod)) % mod;
            power /= 2;
        }

        return ans;
    }

    int minNonZeroProduct(int p) {
        long long range = (1LL << p) - 1;

        long long val = range - 1;
        long long power = range / 2;

        long long ans = solve(val, power);

        ans = (ans * (range % mod)) % mod;

        return ans;
    }
};