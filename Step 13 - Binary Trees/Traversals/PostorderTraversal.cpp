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
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> result;
//         postorder(root, result);
//         return result;
//     }
    
//     void postorder(TreeNode* root, vector<int>& result){
//         if (root == nullptr) return;

//         postorder(root->left, result);
//         postorder(root->right, result);
//         result.push_back(root->val);
//     }
// };



// ITERATIVE using 1 stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if (!root) return postorder;

        stack<TreeNode*> st;
        TreeNode* node = root;
        TreeNode* lastVisited = nullptr;

        while(node != nullptr || !st.empty()){
            if (node != nullptr){
                st.push(node);
                node = node->left;
            }
            else{
                if (st.top()->right != nullptr && lastVisited != st.top()->right) {
                    node = st.top()->right;
                }
                else{
                    postorder.push_back(st.top()->val);
                    lastVisited = st.top();
                    st.pop();
                }
            }
        }
        return postorder;
    }
};