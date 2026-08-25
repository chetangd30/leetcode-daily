class Solution {
  public:
    double power(double b, int e) {
        long long exp = e;

        if (exp < 0) {
            b = 1.0 / b;
            exp = -exp;
        }

        double result = 1.0;

        while (exp > 0) {
            if (exp % 2 == 1)
                result *= b;

            b *= b;
            exp /= 2;
        }

        return result;
    }
};