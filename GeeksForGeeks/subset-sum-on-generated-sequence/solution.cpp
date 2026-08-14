class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {
        if (x == 0)
            return true;

        unordered_set<long long> sums;
        sums.insert(0);

        long long current = s;

        // s is one of the numbers on the paper
        if (s == x)
            return true;

        sums.insert(s);

        for (int a : arr) {
            long long next = current + a;

            if (next > x)
                break;

            vector<long long> newSums;

            for (long long sum : sums) {
                long long ns = sum + next;

                if (ns == x)
                    return true;

                if (ns < x)
                    newSums.push_back(ns);
            }

            for (long long ns : newSums)
                sums.insert(ns);

            current += next;
        }

        return false;
    }
};