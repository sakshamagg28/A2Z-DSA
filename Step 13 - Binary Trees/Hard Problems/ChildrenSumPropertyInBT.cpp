/**
 * ==========================================================
 * Approach 1 : DFS (Recursion)
 * ----------------------------------------------------------
 * Time  : O(N)
 * Space : O(H)
 *
 * Every node should satisfy:
 * node->val = leftValue + rightValue
 *
 * Leaf nodes automatically satisfy the property.
 * ==========================================================
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */

class Solution {
public:

    bool check(TreeNode* root){

        if(root == nullptr)
            return true;

        // Leaf node
        if(root->left == nullptr && root->right == nullptr)
            return true;

        int left = 0;
        int right = 0;

        if(root->left)
            left = root->left->val;

        if(root->right)
            right = root->right->val;

        if(root->val != left + right)
            return false;

        return check(root->left) && check(root->right);
    }

    bool isSumProperty(TreeNode* root) {

        return check(root);
    }
};



/**
 * ==========================================================
 * Approach 2 : Iterative DFS
 * ----------------------------------------------------------
 * Data Structure:
 * Stack
 *
 * Time  : O(N)
 * Space : O(H)
 *
 * Check every node using explicit stack.
 * ==========================================================
 */

class Solution {
public:

    bool isSumProperty(TreeNode* root) {

        if(root == nullptr)
            return true;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){

            TreeNode* node = st.top();
            st.pop();

            // Ignore leaf nodes
            if(node->left == nullptr && node->right == nullptr)
                continue;

            int left = 0;
            int right = 0;

            if(node->left)
                left = node->left->val;

            if(node->right)
                right = node->right->val;

            if(node->val != left + right)
                return false;

            if(node->left)
                st.push(node->left);

            if(node->right)
                st.push(node->right);
        }

        return true;
    }
};