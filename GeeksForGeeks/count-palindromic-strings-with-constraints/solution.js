class Solution {
  public:
    int palindromicStrings(int n, int k) {
        const long long MOD = 1000000007;
        long long ans = 0;
        long long ways = 1;

        for (int half = 0; half <= k; half++) {

            if (half > 0) {
                ways = (ways * (k - half + 1)) % MOD;
            }

            // Even length: 2 * half
            if (half > 0 && 2 * half <= n) {
                ans = (ans + ways) % MOD;
            }

            // Odd length: 2 * half + 1
            // Middle character must be different from
            // all characters used in the paired positions.
            if (2 * half + 1 <= n) {
                long long middleChoices = k - half;
                ans = (ans + ways * middleChoices) % MOD;
            }
        }

        return ans;
    }
};