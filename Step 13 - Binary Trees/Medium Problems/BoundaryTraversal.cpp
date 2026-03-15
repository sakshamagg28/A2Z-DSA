/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int data) : val(data) , left(nullptr) , right(nullptr) {}
 * };
 **/

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
