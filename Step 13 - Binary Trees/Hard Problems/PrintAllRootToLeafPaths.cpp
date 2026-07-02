/**
 * ==========================================================
 * Approach 1 : DFS + Backtracking
 * ----------------------------------------------------------
 * Data Structure:
 * Recursion + Vector
 *
 * Time  : O(N)
 * Space : O(H)
 *
 * Maintain current path.
 * Push current node before recursion.
 * Pop after returning (Backtracking).
 * Standard interview solution.
 * ==========================================================
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */

class Solution {
public:

    vector<vector<int>> ans;

    void dfs(TreeNode* root, vector<int>& path){

        if(root == nullptr)
            return;

        path.push_back(root->val);

        // Leaf node
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(path);
        }
        else{
            dfs(root->left, path);
            dfs(root->right, path);
        }

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> Paths(TreeNode* root){

        vector<int> path;

        dfs(root, path);

        return ans;
    }
};



/**
 * ==========================================================
 * Approach 2 : DFS + Pass by Value
 * ----------------------------------------------------------
 * Data Structure:
 * Recursion
 *
 * Time  : O(N^2) Worst Case
 * Space : O(H)
 *
 * Pass path by value.
 * Every recursive call gets its own copy.
 * Simpler but less efficient.
 * ==========================================================
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */

class Solution {
public:

    vector<vector<int>> ans;

    void dfs(TreeNode* root, vector<int> path){

        if(root == nullptr)
            return;

        path.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(path);
            return;
        }

        dfs(root->left, path);
        dfs(root->right, path);
    }

    vector<vector<int>> Paths(TreeNode* root){

        dfs(root, {});

        return ans;
    }
};