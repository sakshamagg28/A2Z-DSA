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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result = {};
        inorder(root, result);
        return result;
    }

    void inorder(TreeNode* root, vector<int>& result){
        if (root == nullptr) return;

        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
};



// ITERATIVE
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if (!root) return inorder;

        stack<TreeNode*> st;
        TreeNode* node = root;

        while(true){
            if (node != nullptr) {
                st.push(node);
                node = node->left;
            }
            else{
                if (st.empty()) break;
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};



// ITERATIVE Another way (cleaner)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};

        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr || !st.empty()){
            while (curr){
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            ans.push_back(curr->val);

            curr = curr->right;
        }
        
        return ans;
    }
};  