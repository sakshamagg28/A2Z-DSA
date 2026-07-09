// Method: Stack + Controlled Inorder Traversal
// Time Complexity:
//   Constructor : O(H)
//   next()      : O(1) Amortized
//   hasNext()   : O(1)
// Space Complexity: O(H)
// H = Height of the BST
// Standard Interview Solution

class BSTIterator {
    stack<TreeNode*> st;

    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if (node->right)
            pushLeft(node->right);

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};




// Method: Inorder Traversal + Array
// Time Complexity:
//   Constructor : O(N)
//   next()      : O(1)
//   hasNext()   : O(1)
// Space Complexity: O(N)

class BSTIterator {
    vector<int> inorderTraversal;
    int idx = 0;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);
        inorderTraversal.push_back(root->val);
        inorder(root->right);
    }

public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }

    int next() {
        return inorderTraversal[idx++];
    }

    bool hasNext() {
        return idx < inorderTraversal.size();
    }
};