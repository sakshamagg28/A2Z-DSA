// Method: Inorder Traversal (Single Pass)
// Time Complexity: O(N)
// Space Complexity: O(H)
// H = Height of the BST (Recursion Stack)
// Standard Interview Solution

class Solution {
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && prev->val > root->val) {
            if (!first)
                first = prev;
            second = root;
        }

        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
};