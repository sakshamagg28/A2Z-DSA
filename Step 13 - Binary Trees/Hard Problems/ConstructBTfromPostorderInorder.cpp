/**
 * ==========================================================
 * Approach 1 : Hash Map + Recursion
 * ----------------------------------------------------------
 * Time  : O(N)
 * Space : O(N)
 *
 * Postorder gives the root (last element).
 * Inorder splits left and right subtrees.
 * Build right subtree first since we're traversing
 * postorder from the end.
 * ==========================================================
 */

class Solution {
public:
    
    unordered_map<int,int> inorderIndex;
    int postIndex;

    TreeNode* build(vector<int>& postorder, int left, int right){
        if (left > right) return nullptr;

        TreeNode* root = new TreeNode(postorder[postIndex--]);

        int mid = inorderIndex[root->val];

        root->right = build(postorder, mid + 1, right);
        root->left = build(postorder, left, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size()-1;

        for (int i = 0; i < inorder.size(); i++){
            inorderIndex[inorder[i]] = i;
        }

        return build(postorder, 0, inorder.size()-1);
    }
};



/**
 * ==========================================================
 * Approach 2 : Recursion + Linear Search
 * ----------------------------------------------------------
 * Time  : O(N²)
 * Space : O(H)
 *
 * Find root in inorder using linear search.
 * Build right subtree first.
 * ==========================================================
 */

class Solution {
public:
    int postIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int left, int right){
        if(left > right) return nullptr;

        TreeNode* root = new TreeNode(postorder[postIndex--]);

        int mid = left;
        while(inorder[mid] != root->val)
            mid++;

        root->right = build(inorder, postorder, mid + 1, right);
        root->left = build(inorder, postorder, left, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};