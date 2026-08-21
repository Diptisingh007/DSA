class Solution {
public:
    using ll = long long;

    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(), coins.end());
        vector<int> temp;
        for (int c : coins) {
            bool redundant = false;

            for (int x : temp) {
                if (c % x == 0) {
                    redundant = true;
                    break;
                }
            }
            if (!redundant) {
                temp.push_back(c);
            }
        }

        int n = temp.size();

        auto check = [&](ll mid) {

            ll total = 0;
            for (int i = 1; i <= n; i++) {
                int q = (1 << i) - 1;

                while (q < (1 << n)) {
                    ll l = 1;

                    for (int j = 0; j < n; j++) {
                        if ((q >> j) & 1) {
                            l = lcm(l, (ll)temp[j]);

                            if (l > mid) {
                                break;
                            }
                        }
                    }

                    if (l <= mid) {
                        ll count = mid / l;

                        if (i % 2 == 1)
                            total += count;
                        else
                            total -= count;
                    }

                    int c = q & -q;
                    int r = q + c;

                    q = (((r ^ q) >> 2) / c) | r;
                }
            }

            return total >= k;
        };

        // Step 4: Binary search
        ll low = k;
        ll high = 1LL * temp[0] * k;

        while (low < high) {

            ll mid = low + (high - low) / 2;

            if (check(mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};