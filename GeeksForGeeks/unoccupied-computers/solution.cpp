class Solution {
  public:
    int solve(int n, string s) {
        // 0 = not arrived
        // 1 = using a computer
        // 2 = rejected
        int state[26] = {0};

        int available = n;
        int rejected = 0;

        for (char c : s) {
            int id = c - 'A';

            // First occurrence: customer arrives
            if (state[id] == 0) {
                if (available > 0) {
                    state[id] = 1;
                    available--;
                } else {
                    state[id] = 2;
                    rejected++;
                }
            }
            // Second occurrence
            else if (state[id] == 1) {
                // Customer had a computer, so free it
                available++;
                state[id] = 0;
            }
            else {
                // Customer was rejected, so nothing to free
                state[id] = 0;
            }
        }

        return rejected;
    }
};