class Solution {
  public:
    int josephus(int n, int k) {
        int survivor = 0;  // J(1, k)

        for (int size = 2; size <= n; size++) {
            survivor = (survivor + k) % size;
        }

        return survivor + 1;
    }
};