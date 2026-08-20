class Solution {
  public:
    int maxDiff(Node* root) {
        if (root == nullptr)
            return 0;

        int ans = INT_MIN;

        function<int(Node*)> dfs = [&](Node* node) {
            if (node == nullptr)
                return INT_MAX;

            int minDescendant = min(dfs(node->left), dfs(node->right));

            if (minDescendant != INT_MAX)
                ans = max(ans, node->data - minDescendant);

            return min(node->data, minDescendant);
        };

        dfs(root);

        return ans;
    }
};