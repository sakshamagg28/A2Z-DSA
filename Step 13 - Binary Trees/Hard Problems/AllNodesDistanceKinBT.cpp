/**
 * ==========================================================
 * Approach 1 : Parent Map + BFS (Standard)
 * ----------------------------------------------------------
 * Data Structure:
 * Queue + HashMap + HashSet
 *
 * Time  : O(N)
 * Space : O(N)
 *
 * 1. Build parent pointers.
 * 2. Perform BFS from target.
 * 3. Traverse left, right and parent.
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

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> parent;

        queue<TreeNode*> q;
        q.push(root);

        // Build parent map
        while(!q.empty()){

            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }

            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int distance = 0;

        while(!q.empty()){

            int size = q.size();

            if(distance == k)
                break;

            distance++;

            while(size--){

                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited.count(node->left)){
                    visited.insert(node->left);
                    q.push(node->left);
                }

                if(node->right && !visited.count(node->right)){
                    visited.insert(node->right);
                    q.push(node->right);
                }

                if(parent.count(node) && !visited.count(parent[node])){
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
        }

        vector<int> ans;

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};



/**
 * ==========================================================
 * Approach 2 : DFS Distance Propagation
 * ----------------------------------------------------------
 * Time  : O(N)
 * Space : O(H)
 *
 * Find target using DFS.
 * While returning, calculate distances upward.
 * Explore opposite subtree when required.
 *
 * More difficult but no parent map needed.
 * ==========================================================
 */

class Solution {
public:

    vector<int> ans;
    int K;

    void collect(TreeNode* root,int dist){

        if(!root)
            return;

        if(dist==K){
            ans.push_back(root->val);
            return;
        }

        collect(root->left,dist+1);
        collect(root->right,dist+1);
    }

    int dfs(TreeNode* root,TreeNode* target){

        if(!root)
            return -1;

        if(root==target){

            collect(root,0);

            return 1;
        }

        int left=dfs(root->left,target);

        if(left!=-1){

            if(left==K)
                ans.push_back(root->val);

            collect(root->right,left+1);

            return left+1;
        }

        int right=dfs(root->right,target);

        if(right!=-1){

            if(right==K)
                ans.push_back(root->val);

            collect(root->left,right+1);

            return right+1;
        }

        return -1;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        K=k;

        dfs(root,target);

        return ans;
    }
};