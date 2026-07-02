/**
 * ==========================================================
 * Approach 1 : BFS Level Order
 * ----------------------------------------------------------
 * Data Structure:
 * Queue
 *
 * Time  : O(N)
 * Space : O(N)
 *
 * Store the last node of every level.
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

    vector<int> rightSideView(TreeNode* root) {

        if(root == nullptr)
            return {};

        vector<int> ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int size = q.size();

            for(int i=0;i<size;i++){

                TreeNode* node = q.front();
                q.pop();

                // Last node of current level
                if(i == size-1)
                    ans.push_back(node->val);

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }
        }

        return ans;
    }
};



/**
 * ==========================================================
 * Approach 2 : BFS (Right First)
 * ----------------------------------------------------------
 * Data Structure:
 * Queue
 *
 * Time  : O(N)
 * Space : O(N)
 *
 * Push right child before left child.
 * First node of every level becomes the answer.
 * ==========================================================
 */

class Solution {
public:

    vector<int> rightSideView(TreeNode* root) {

        if(root == nullptr)
            return {};

        vector<int> ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int size = q.size();

            for(int i=0;i<size;i++){

                TreeNode* node = q.front();
                q.pop();

                // First node after pushing right first
                if(i==0)
                    ans.push_back(node->val);

                if(node->right)
                    q.push(node->right);

                if(node->left)
                    q.push(node->left);
            }
        }

        return ans;
    }
};



/**
 * ==========================================================
 * Approach 3 : DFS (Right First)
 * ----------------------------------------------------------
 * Data Structure:
 * Recursion
 *
 * Time  : O(N)
 * Space : O(H)
 *
 * Visit Right -> Left.
 * First node reached at every depth is the answer.
 * Most elegant recursive solution.
 * ==========================================================
 */

class Solution {
public:

    void dfs(TreeNode* root, int level, vector<int>& ans){

        if(root == nullptr)
            return;

        // First node at this level
        if(level == ans.size())
            ans.push_back(root->val);

        dfs(root->right, level+1, ans);
        dfs(root->left, level+1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        dfs(root,0,ans);

        return ans;
    }
};



// Another BFS approach using unordered_map to store the last node of each level
// Time complexity: O(N), Space complexity: O(N)

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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        
        unordered_map<int,int> mp;
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        int maxRow = 0;

        while(!q.empty()){
            auto [node, row] = q.front();
            q.pop();

            mp[row] = node->val;

            maxRow = max(maxRow, row);

            if (node->left) q.push({node->left, row + 1});
            if (node->right) q.push({node->right, row + 1});
        }

        vector<int> ans;

        for (int row = 0; row <= maxRow; row++){
            ans.push_back(mp[row]);
        }

        return ans;
    }
};