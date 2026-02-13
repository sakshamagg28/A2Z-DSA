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



// // ITERATIVE USING 1 STACK
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> postorder;
//         if (!root) return postorder;

//         stack<TreeNode*> st;
//         TreeNode* node = root;
//         TreeNode* lastVisited = nullptr;

//         while(node != nullptr || !st.empty()){
//             if (node != nullptr){
//                 st.push(node);
//                 node = node->left;
//             }
//             else{
//                 if (st.top()->right != nullptr && lastVisited != st.top()->right) {
//                     node = st.top()->right;
//                 }
//                 else{
//                     postorder.push_back(st.top()->val);
//                     lastVisited = st.top();
//                     st.pop();
//                 }
//             }
//         }
//         return postorder;
//     }
// };




// ITERATIVE USING 2 STACKS
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if (!root) return postorder;

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while(!st1.empty()){
            root = st1.top();
            st1.pop();

            st2.push(root);

            if(root->left) st1.push(root->left);
            if(root->right) st1.push(root->right);
        }

        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        
        return postorder;
    }
};