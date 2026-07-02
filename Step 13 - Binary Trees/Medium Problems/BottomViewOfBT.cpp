/**
 * ==========================================================
 * Approach 1 : DFS + Map
 * ----------------------------------------------------------
 * Data Structure:
 * map<column, {maximum row, node value}>
 *
 * Time  : O(N log N)
 * Space : O(N)
 *
 * Store the bottommost (maximum row) node for every column.
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

    void dfs(TreeNode* root, int row, int col,
             map<int, pair<int,int>>& mp){

        if(!root) return;

        // Replace if current node is lower
        if(mp.find(col) == mp.end() || row >= mp[col].first)
            mp[col] = {row, root->val};

        dfs(root->left, row + 1, col - 1, mp);
        dfs(root->right, row + 1, col + 1, mp);
    }

    vector<int> bottomView(TreeNode *root) {

        map<int, pair<int,int>> mp;

        dfs(root,0,0,mp);

        vector<int> ans;

        for(auto &it : mp)
            ans.push_back(it.second.second);

        return ans;
    }
};



/**
 * ==========================================================
 * Approach 2 : BFS + Map
 * ----------------------------------------------------------
 * Data Structure:
 * queue<pair<TreeNode*, column>>
 * map<column, node value>
 *
 * Time  : O(N log N)
 * Space : O(N)
 *
 * Every new node at a column replaces the previous one.
 * Since BFS is level order, the last node seen is the answer.
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

    vector<int> bottomView(TreeNode *root) {

        if(root == nullptr)
            return {};

        map<int,int> mp;

        queue<pair<TreeNode*,int>> q;

        q.push({root,0});

        while(!q.empty()){

            auto [node,col] = q.front();
            q.pop();

            // Always overwrite
            mp[col] = node->val;

            if(node->left)
                q.push({node->left,col-1});

            if(node->right)
                q.push({node->right,col+1});
        }

        vector<int> ans;

        for(auto &it : mp)
            ans.push_back(it.second);

        return ans;
    }
};



/**
 * ==========================================================
 * Approach 3 : BFS + Unordered Map
 * ----------------------------------------------------------
 * Data Structure:
 * queue<pair<TreeNode*, column>>
 * unordered_map<column, node value>
 *
 * Time  : O(N) Average
 * Space : O(N)
 *
 * Maintain minimum and maximum column.
 * Always overwrite previous node.
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

    vector<int> bottomView(TreeNode *root) {

        if(root == nullptr)
            return {};

        unordered_map<int,int> mp;

        queue<pair<TreeNode*,int>> q;

        q.push({root,0});

        int minCol = 0;
        int maxCol = 0;

        while(!q.empty()){

            auto [node,col] = q.front();
            q.pop();

            // Always overwrite
            mp[col] = node->val;

            minCol = min(minCol,col);
            maxCol = max(maxCol,col);

            if(node->left)
                q.push({node->left,col-1});

            if(node->right)
                q.push({node->right,col+1});
        }

        vector<int> ans;

        for(int col=minCol; col<=maxCol; col++)
            ans.push_back(mp[col]);

        return ans;
    }
};