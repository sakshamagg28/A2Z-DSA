/**
 * ==========================================================
 * Approach 1 : BFS + Indexing (Standard)
 * ----------------------------------------------------------
 * Data Structure:
 * Queue<pair<TreeNode*, index>>
 *
 * Time  : O(N)
 * Space : O(N)
 *
 * Assign indices as in a complete binary tree.
 * Left Child  = 2 * index + 1
 * Right Child = 2 * index + 2
 *
 * Normalize indices at every level to prevent overflow.
 * Width = lastIndex - firstIndex + 1
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        long long ans = 0;

        queue<pair<TreeNode*, long long>> q;

        q.push({root, 0});

        while(!q.empty()){
            int size = q.size();

            long long minIndex = q.front().second;

            long long first = 0;
            long long last = 0;

            for (int i = 0; i < size; i++){
                auto [node, index] = q.front();
                q.pop();

                index -= minIndex;

                if (i == 0) first = index;
                if (i == size - 1) last = index;

                if (node->left) q.push({node->left, 2*index + 1});
                if (node->right) q.push({node->right, 2*index + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};



/**
 * ==========================================================
 * Approach 2 : DFS + First Index
 * ----------------------------------------------------------
 * Data Structure:
 * Recursion + Vector
 *
 * Time  : O(N)
 * Space : O(H)
 *
 * Store first index seen at every level.
 * Width = currentIndex - firstIndex + 1
 * ==========================================================
 */

 
class Solution {
public:

    long long ans = 0;

    vector<long long> firstIndex;

    void dfs(TreeNode* root,int level,long long index){

        if(root==nullptr)
            return;

        if(level==firstIndex.size())
            firstIndex.push_back(index);

        ans=max(ans,index-firstIndex[level]+1);

        dfs(root->left,level+1,2*index+1);
        dfs(root->right,level+1,2*index+2);
    }

    int widthOfBinaryTree(TreeNode* root) {

        dfs(root,0,0);

        return ans;
    }
};