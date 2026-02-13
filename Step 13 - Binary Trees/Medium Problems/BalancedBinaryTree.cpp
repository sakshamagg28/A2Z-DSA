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



// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         if (!root) return true;

//         int heightLeft = heightOfTree(root->left);
//         int heightRight = heightOfTree(root->right);

//         if (abs(heightLeft - heightRight) > 1) return false;

//         return isBalanced(root->left) && isBalanced(root->right);
//     }

//     int heightOfTree(TreeNode* root){
//         if (!root) return 0;

//         return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
//     }
// };



// OPTIMAL APPROACH
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }

private:
    int check(TreeNode* root) {
        if (!root) return 0;

        int left = check(root->left);
        if (left == -1) return -1;

        int right = check(root->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;

        return 1 + max(left, right);
    }
};