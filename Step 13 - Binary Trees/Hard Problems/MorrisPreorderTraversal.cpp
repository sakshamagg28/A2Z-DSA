/**
 * ==========================================================
 * Morris Preorder Traversal
 * ----------------------------------------------------------
 * Time  : O(N)
 * Space : O(1)
 *
 * Logic:
 *
 * Preorder = Root -> Left -> Right
 *
 * Normally recursion/stack is needed to return from the
 * left subtree back to the parent.
 *
 * Morris Traversal avoids this by creating a temporary link
 * (thread) from the preorder node's inorder predecessor
 * (rightmost node of left subtree) back to the current node.
 *
 * Inorder Predecessor:
 * -> Rightmost node in the current node's left subtree.
 *
 * Cases:
 *
 * 1. If current has no left child:
 *      Left subtree does not exist.
 *      Visit current and move to right child.
 *
 * 2. Otherwise find its inorder predecessor.
 *
 *      a) predecessor->right == NULL
 *         We are visiting current for the FIRST time.
 *         Since preorder visits Root BEFORE Left,
 *         visit current immediately.
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
 *         This means the left subtree has already been
 *         completely processed.
 *
 *         Remove the temporary thread to restore the tree.
 *
 *         DO NOT visit current again because it was already
 *         visited during the first encounter.
 *
 *         Move to right child.
 *
 * Every temporary thread is created once and removed once,
 * so the original tree is restored.
 *
 * Difference from Morris Inorder:
 *
 * Inorder  : Visit when removing the thread.
 * Preorder : Visit when creating the thread.
 * ==========================================================
 */

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

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

                    // Preorder visits Root first
                    ans.push_back(curr->val);

                    // Create temporary thread
                    pred->right = curr;

                    // Explore left subtree
                    curr = curr->left;
                }
                else{

                    // Left subtree finished
                    // Remove thread and restore tree
                    pred->right = nullptr;

                    // Root already visited
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};