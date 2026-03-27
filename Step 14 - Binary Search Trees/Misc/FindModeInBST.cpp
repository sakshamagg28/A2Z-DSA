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
    int currCount = 0, maxCount = 0;
    vector<int> modes;
    TreeNode* prev = nullptr;
public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return modes;
    }

    void inorder(TreeNode* root){
        if (!root) return;

        inorder(root->left);
        if (prev && prev->val == root->val){
            currCount++;
        }
        else {
            currCount = 1;
        }
        
        if (currCount > maxCount){
            maxCount = currCount;
            modes.clear();
            modes.push_back(root->val);
        }
        else if (currCount == maxCount){
            modes.push_back(root->val);
        }
        prev = root;
        inorder(root->right);
    }
};