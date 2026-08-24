class Solution {
  public:
    int prefixStrings(int n) {
        const long long MOD = 1000000007;

        // dp[j] = C(i, j)
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        // Calculate C(2n, n)
        for (int i = 1; i <= 2 * n; i++) {
            for (int j = min(i, n); j >= 1; j--) {
                dp[j] = (dp[j] + dp[j - 1]) % MOD;
            }
        }

        long long comb = dp[n];

        // C(n) = C(2n,n) / (n+1)
        // Use modular inverse of (n+1)
        long long inverse = 1;
        long long base = n + 1;
        long long exp = MOD - 2;

        while (exp > 0) {
            if (exp & 1)
                inverse = (inverse * base) % MOD;

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return (comb * inverse) % MOD;
    }
};