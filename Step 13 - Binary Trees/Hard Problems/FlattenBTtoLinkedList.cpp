/**
 * ==========================================================
 * Approach 1 : Morris Traversal (Expected)
 * ----------------------------------------------------------
 * Time  : O(N)
 * Space : O(1)
 *
 * Standard interview solution.
 *
 * Key Idea:
 * Find the rightmost node of the left subtree.
 * Connect it to the current node's right subtree.
 * Move the left subtree to the right.
 * ==========================================================
 */

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while(curr){
            if(curr->left){
                TreeNode* pred = curr->left;
                while(pred->right)
                    pred = pred->right;

                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};



/**
 * ==========================================================
 * Approach 2 : Reverse DFS
 * ----------------------------------------------------------
 * Time  : O(N)
 * Space : O(H)
 *
 * Key Idea:
 * Traverse Right -> Left -> Root.
 * Keep the previously processed node and
 * attach it as the current node's right child.
 * ==========================================================
 */

class Solution {
public:
    TreeNode* prev = nullptr;

    void dfs(TreeNode* root){
        if(!root) return;

        dfs(root->right);
        dfs(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;
    }

    void flatten(TreeNode* root) {
        dfs(root);
    }
};



/**
 * ==========================================================
 * Approach 3 : Stack
 * ----------------------------------------------------------
 * Time  : O(N)
 * Space : O(N)
 *
 * Key Idea:
 * Simulate preorder traversal.
 * Push right child first, then left child.
 * ==========================================================
 */

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();

            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);

            if(!st.empty())
                curr->right = st.top();

            curr->left = nullptr;
        }
    }
};