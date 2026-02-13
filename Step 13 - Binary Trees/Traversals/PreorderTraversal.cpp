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


// // RECURSIVE
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> result = {};
//         helper(root, result);
//         return result;
//     }

//     void helper(TreeNode* node, vector<int>& result){
//         if (node == nullptr) return;

//         result.push_back(node->val);

//         helper(node->left, result);
//         helper(node->right, result);
//     }
// };



// ITERATIVE
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            root = st.top();
            st.pop();

            result.push_back(root->val);

            if(root->right) st.push(root->right);
            if(root->left) st.push(root->left);
        }

        return result;
    }
};