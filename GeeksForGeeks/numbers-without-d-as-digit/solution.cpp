class Solution {
public:
    int countWithout(int n, int d) {
        if (n == 0)
            return 0;

        string s = to_string(n);
        int len = s.size();

        long long dp[12][2][2] = {};

        dp[0][1][0] = 1;

        for (int pos = 0; pos < len; pos++) {
            for (int tight = 0; tight <= 1; tight++) {
                for (int started = 0; started <= 1; started++) {

                    long long ways = dp[pos][tight][started];

                    if (ways == 0)
                        continue;

                    int limit = tight ? s[pos] - '0' : 9;

                    for (int digit = 0; digit <= limit; digit++) {
                        int newTight = tight && (digit == limit);
                        int newStarted = started || (digit != 0);

                        // Ignore digit d after the number has started.
                        if (newStarted && digit == d)
                            continue;

                        dp[pos + 1][newTight][newStarted] += ways;
                    }
                }
            }
        }

        long long answer = 0;

        // Count numbers that have actually started.
        answer = dp[len][0][1] + dp[len][1][1];

        return answer;
    }
};