class Solution {
  public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> height(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {

            // Update consecutive 1s for each column
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1)
                    height[j]++;
                else
                    height[j] = 0;
            }

            // Make a copy because original height[]
            // must retain column information
            vector<int> sortedHeight = height;

            sort(sortedHeight.begin(), sortedHeight.end(), greater<int>());

            // Columns can be rearranged freely
            for (int j = 0; j < m; j++) {
                int area = sortedHeight[j] * (j + 1);
                ans = max(ans, area);
            }
        }

        return ans;
    }
};