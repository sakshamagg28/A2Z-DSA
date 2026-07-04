/**
 * ==========================================================
 * Morris Preorder Traversal
 * ----------------------------------------------------------
 * Time  : O(N)
 * Space : O(1)
 *
 * Logic:
 * 1. If current node has no left child:
 *      - Visit current node.
 *      - Move to right child.
 *
 * 2. Otherwise:
 *      - Find the inorder predecessor
 *        (rightmost node of current's left subtree).
 *
 *      - If predecessor->right is NULL:
 *          * Visit current node (Preorder: Root first).
 *          * Create a temporary thread:
 *                predecessor->right = current
 *          * Move to left child.
 *
 *      - Else (thread already exists):
 *          * Remove the thread.
 *          * Move to right child.
 *
 * Since every temporary thread is removed later,
 * the original tree is restored.
 * ==========================================================
 */

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while(curr){
            if(curr->left == nullptr){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* pred = curr->left;

                while(pred->right && pred->right != curr)
                    pred = pred->right;

                if(pred->right == nullptr){
                    ans.push_back(curr->val);
                    pred->right = curr;
                    curr = curr->left;

                }
                else{
                    pred->right = nullptr;
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};