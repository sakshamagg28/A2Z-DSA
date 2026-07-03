/**
 * ==========================================================
 * Approach 1 : Complete Tree Optimization
 * ----------------------------------------------------------
 * Time  : O((log N)^2)
 * Space : O(log N)
 *
 * Compute left height and right height.
 *
 * If both heights are equal:
 *      Perfect Binary Tree
 *      Nodes = 2^height - 1
 *
 * Otherwise recursively count left and right subtree.
 *
 * Expected interview solution.
 * ==========================================================
 */

class Solution {
public:

    int leftHeight(TreeNode* root){
        int height = 0;

        while(root){
            height++;
            root = root->left;
        }

        return height;
    }

    int rightHeight(TreeNode* root){
        int height = 0;

        while(root){
            height++;
            root = root->right;
        }

        return height;
    }

    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        // Perfect Binary Tree
        if(lh == rh)
            return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};




/**
 * ==========================================================
 * Approach 2 : DFS
 * ----------------------------------------------------------
 * Time  : O(N)
 * Space : O(H)
 *
 * Count every node recursively.
 * Works for any binary tree.
 * ==========================================================
 */

class Solution {
public:

    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};