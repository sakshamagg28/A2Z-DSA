// Method: Postorder DFS + Bottom-Up Information
// Time Complexity: O(N)
// Space Complexity: O(H)
// H = Height of the Tree
// Standard Interview Solution

class Solution {
    struct NodeInfo {
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };

    int ans = 0;

    NodeInfo dfs(TreeNode* root) {
        if (!root)
            return {true, INT_MAX, INT_MIN, 0};

        NodeInfo left = dfs(root->left);
        NodeInfo right = dfs(root->right);

        if (left.isBST && right.isBST &&
            root->val > left.maxVal &&
            root->val < right.minVal) {

            int sum = left.sum + right.sum + root->val;
            ans = max(ans, sum);

            return {
                true,
                min(root->val, left.minVal),
                max(root->val, right.maxVal),
                sum
            };
        }

        return {false, INT_MIN, INT_MAX, 0};
    }

public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};