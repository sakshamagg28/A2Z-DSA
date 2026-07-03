/**
 * ==========================================================
 * Approach 1 : Parent Map + BFS
 * ----------------------------------------------------------
 * Time  : O(N)
 * Space : O(N)
 *
 * 1. Build parent pointers.
 * 2. Find target node.
 * 3. BFS in all three directions.
 * 4. Every BFS level = 1 second.
 * ==========================================================
 */

class Solution {
public:

    int minTime(TreeNode* root, int target) {
        unordered_map<TreeNode*, TreeNode*> parent;

        TreeNode* targetNode = nullptr;

        queue<TreeNode*> q;
        q.push(root);

        // Build parent map and locate target node
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->val == target)
                targetNode = node;

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        unordered_set<TreeNode*> visited;

        q.push(targetNode);
        visited.insert(targetNode);

        int time = -1;

        while (!q.empty()) {
            int size = q.size();
            time++;

            while (size--) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if (parent.count(node) && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
        }

        return time;
    }
};



/**
 * ==========================================================
 * Approach 2 : DFS Distance Propagation
 * ----------------------------------------------------------
 * Time  : O(N)
 * Space : O(H)
 *
 * Find target recursively.
 * While returning, compute burn time.
 * No parent map required.
 *
 * Hard interview solution.
 * ==========================================================
 */

class Solution {
public:

    int answer = 0;

    // Height of subtree
    int height(TreeNode* root) {

        if (!root)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    // Returns distance from current node to target.
    // Returns -1 if target not found.
    int dfs(TreeNode* root, int target) {
        if (!root) return -1;

        if (root->val == target) {
            answer = max(answer, height(root) - 1);
            return 1;
        }

        int left = dfs(root->left, target);

        if (left != -1) {
            answer = max(answer, left + height(root->right));
            return left + 1;
        }

        int right = dfs(root->right, target);

        if (right != -1) {
            answer = max(answer, right + height(root->left));
            return right + 1;
        }

        return -1;
    }

    int minTime(TreeNode* root, int target) {
        dfs(root, target);
        return answer;
    }
};