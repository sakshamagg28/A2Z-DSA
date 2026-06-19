/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int data) : val(data) , left(nullptr) , right(nullptr) {}
 * };
 **/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
 * };
 **/

 // Best Solution
class Solution {
public:
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }

    void addLeftBoundary(TreeNode* root, vector<int>& ans) {
        TreeNode* curr = root->left;

        while (curr) {
            if (!isLeaf(curr))
                ans.push_back(curr->data);

            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void addLeaves(TreeNode* root, vector<int>& ans) {
        if (!root) return;

        if (isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }

        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }

    void addRightBoundary(TreeNode* root, vector<int>& ans) {
        TreeNode* curr = root->right;
        vector<int> temp;

        while (curr) {
            if (!isLeaf(curr))
                temp.push_back(curr->data);

            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }

        for (int i = temp.size() - 1; i >= 0; i--) {
            ans.push_back(temp[i]);
        }
    }

    vector<int> boundary(TreeNode* root) {
        vector<int> ans;

        if (!root) return ans;

        if (!isLeaf(root))
            ans.push_back(root->data);

        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);

        return ans;
    }
};




// My solution
class Solution{
public:
    vector<int> boundary(TreeNode* root){
        if (!root) return {};
        
        vector<int> traversal;
        vector<int> left = leftBoundary(root);
        vector<int> right = rightBoundary(root);
        vector<int> leaf = leaves(root);

        if (!isLeaf(root)) traversal.push_back(root->val);
        traversal.insert(traversal.end(), left.begin(), left.end());
        traversal.insert(traversal.end(), leaf.begin(), leaf.end());
        reverse(right.begin(), right.end());
        traversal.insert(traversal.end(), right.begin(), right.end());

        return traversal;
    }

    vector<int> leftBoundary(TreeNode* root){
        vector<int> leftBound;
        TreeNode* node = root->left;
        while (node){
            if (!isLeaf(node)) leftBound.push_back(node->val);
            if (node->left) node = node->left;
            else if (node->right) node = node->right;
            else break;
        }
        return leftBound;
    }

    vector<int> rightBoundary(TreeNode* root){
        vector<int> rightBound;
        TreeNode* node = root->right;
        while (node){
            if (!isLeaf(node)) rightBound.push_back(node->val);
            if (node->right) node = node->right;
            else if (node->left) node = node->left;
            else break;
        }
        return rightBound;
    }

    vector<int> leaves(TreeNode* root){
        if (!root) return {};
        vector<int> leaf;
        if (!root->left && !root->right) return {root->val};

        vector<int> left = leaves(root->left);
        vector<int> right = leaves(root->right);

        leaf.insert(leaf.end(), left.begin(), left.end());
        leaf.insert(leaf.end(), right.begin(), right.end());
        return leaf;
    }
    
private:
    bool isLeaf(TreeNode* node) {
        return node && !node->left && !node->right;
    }
};
