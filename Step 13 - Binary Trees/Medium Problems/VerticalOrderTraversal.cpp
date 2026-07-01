/**
 * ==========================================================
 * Approach 1 : DFS + map + map + multiset
 * ----------------------------------------------------------
 * Data Structure:
 * map<col, map<row, multiset<values>>>
 *
 * Time  : O(N log N)
 * Space : O(N)
 *
 * Most common interview solution.
 * ==========================================================
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    void dfs(TreeNode* root, int row, int col,
             map<int, map<int, multiset<int>>>& mp){

        if(!root) return;

        // Store current node
        mp[col][row].insert(root->val);

        dfs(root->left, row + 1, col - 1, mp);
        dfs(root->right, row + 1, col + 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int, multiset<int>>> mp;

        dfs(root, 0, 0, mp);

        vector<vector<int>> ans;

        // Traverse columns from left to right
        for(auto &col : mp){

            vector<int> temp;

            // Traverse rows from top to bottom
            for(auto &row : col.second){

                // Values automatically sorted by multiset
                for(int val : row.second)
                    temp.push_back(val);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};



/**
 * ==========================================================
 * Approach 2 : DFS + Vector + Sort
 * ----------------------------------------------------------
 * Data Structure:
 * vector<tuple<col,row,value>>
 *
 * Time  : O(N log N)
 * Space : O(N)
 *
 * Cleanest implementation.
 * Tuple sorting automatically sorts by:
 * Column -> Row -> Value
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

    vector<tuple<int,int,int>> nodes;

    void dfs(TreeNode* root, int row, int col){

        if(!root) return;

        nodes.push_back({col, row, root->val});

        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        dfs(root, 0, 0);

        // Sort by column, then row, then value
        sort(nodes.begin(), nodes.end());

        vector<vector<int>> ans;

        int prevCol = INT_MIN;

        for(auto &[col,row,val] : nodes){

            if(col != prevCol){
                ans.push_back({});
                prevCol = col;
            }

            ans.back().push_back(val);
        }

        return ans;
    }
};



/**
 * ==========================================================
 * Approach 3 : DFS + Min Heap (Priority Queue)
 * ----------------------------------------------------------
 * Data Structure:
 * priority_queue<tuple<col,row,value>, ..., greater<>>
 *
 * Time  : O(N log N)
 * Space : O(N)
 *
 * Heap automatically pops nodes in order:
 * Column -> Row -> Value
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

    priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>
    > pq;

    void dfs(TreeNode* root, int row, int col){

        if(!root) return;

        pq.push({col, row, root->val});

        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        dfs(root, 0, 0);

        vector<vector<int>> ans;

        int prevCol = INT_MIN;

        while(!pq.empty()){

            auto [col,row,val] = pq.top();
            pq.pop();

            if(col != prevCol){
                ans.push_back({});
                prevCol = col;
            }

            ans.back().push_back(val);
        }

        return ans;
    }
};