class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> sum;
        for (long long i = 0; i < n; ++i) {
            long long currentSum = 0;
            for (long long j = i; j < n; ++j) {
                currentSum += nums[j];
                sum.push_back(currentSum);
            }
        }

        sort(sum.begin(), sum.end());
        long long ans = 0;
        for (long long i = left - 1; i <= right - 1; ++i) {
            ans += sum[i];
        }
        const int MOD = 1e9 + 7;
        return static_cast<int>(ans % MOD);
    }
};