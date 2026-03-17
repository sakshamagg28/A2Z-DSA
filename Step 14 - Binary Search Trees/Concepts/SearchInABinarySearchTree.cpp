/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* node = root;
        while(true){
            if (val > node->val && node->right){
                node = node->right;
            }
            else if (val < node->val && node->left){
                node = node->left;
            }
            else if (val == node->val){
                break;
            }
            else {
                return NULL;
            }
        }
        return node;
    }
};