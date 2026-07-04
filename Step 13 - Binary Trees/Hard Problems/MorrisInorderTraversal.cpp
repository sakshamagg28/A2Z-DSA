/**
 * ==========================================================
 * Morris Inorder Traversal
 * ----------------------------------------------------------
 * Time  : O(N)
 * Space : O(1)
 *
 * Logic:
 *
 * Inorder = Left -> Root -> Right
 *
 * Normally recursion/stack is needed to return from the
 * left subtree back to the parent.
 *
 * Morris Traversal avoids this by creating a temporary link
 * (thread) from the inorder predecessor back to the parent.
 *
 * Inorder Predecessor:
 * -> Rightmost node in the current node's left subtree.
 *
 * Cases:
 *
 * 1. If current has no left child:
 *      Left subtree is already finished.
 *      Visit current and move right.
 *
 * 2. Otherwise find its inorder predecessor.
 *
 *      a) predecessor->right == NULL
 *         We are visiting current for the FIRST time.
 *         Left subtree is NOT processed yet.
 *
 *         Create a temporary thread:
 *              predecessor->right = current
 *
 *         This thread acts like a return address.
 *         After finishing the left subtree we can return
 *         to current without recursion.
 *
 *         Move to left child.
 *
 *      b) predecessor->right == current
 *         We reached current AGAIN through the thread.
 *         This means the entire left subtree has already
 *         been processed.
 *
 *         Remove the temporary thread to restore the tree.
 *
 *         Now visit current (Left is done).
 *
 *         Move to right child.
 *
 * Every temporary thread is created once and removed once,
 * so the original tree remains unchanged.
 * ==========================================================
 */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        TreeNode* curr = root;

        while(curr){

            // No left subtree -> visit immediately
            if(curr->left == nullptr){

                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{

                // Find inorder predecessor
                TreeNode* pred = curr->left;

                while(pred->right && pred->right != curr)
                    pred = pred->right;

                // First visit to current
                if(pred->right == nullptr){

                    // Create temporary thread to return later
                    pred->right = curr;

                    // Process left subtree first
                    curr = curr->left;
                }
                else{

                    // Returned from left subtree
                    // Remove thread and restore tree
                    pred->right = nullptr;

                    // Left subtree is complete
                    ans.push_back(curr->val);

                    // Move to right subtree
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};