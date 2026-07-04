/**
 * ==========================================================
 * Approach 1 : Hash Map + Recursion
 * ----------------------------------------------------------
 * Time  : O(N)
 * Space : O(N)
 *
 * Store every inorder value and its index.
 * This avoids repeated linear searches.
 *
 * Expected interview solution.
 * ==========================================================
 */

class Solution {
public:

    unordered_map<int,int> inorderIndex;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, int left, int right){
        if(left > right) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex++]);

        int mid = inorderIndex[root->val];

        root->left = build(preorder, left, mid - 1);
        root->right = build(preorder, mid + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++)
            inorderIndex[inorder[i]] = i;

        return build(preorder, 0, inorder.size()-1);
    }
};



/**
 * ==========================================================
 * Approach 2 : Recursion + Linear Search
 * ----------------------------------------------------------
 * Time  : O(N²)
 * Space : O(H)
 *
 * For every root:
 * 1. Take current preorder element.
 * 2. Find its position in inorder by linear search.
 * 3. Recursively build left and right subtree.
 * ==========================================================
 */

class Solution {
public:

    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right){
        if(left > right)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex++]);

        int mid = left;

        while(inorder[mid] != root->val)
            mid++;

        root->left = build(preorder, inorder, left, mid - 1);
        root->right = build(preorder, inorder, mid + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, inorder.size()-1);
    }
};