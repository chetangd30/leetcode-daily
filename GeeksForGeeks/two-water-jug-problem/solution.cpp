class Solution {
  public:
    int pour(int from, int to, int d) {
        int a = 0, b = 0;
        int steps = 0;

        while (a != d && b != d) {
            if (a == 0) {
                a = from;
                steps++;
            }
            else if (b == to) {
                b = 0;
                steps++;
            }
            else {
                int transfer = min(a, to - b);
                a -= transfer;
                b += transfer;
                steps++;
            }
        }

        return steps;
    }

    int minSteps(int m, int n, int d) {
        if (d > max(m, n))
            return -1;

        if (d % std::gcd(m, n) != 0)
            return -1;

        if (d == m || d == n)
            return 1;

        return min(pour(m, n, d), pour(n, m, d));
    }
};