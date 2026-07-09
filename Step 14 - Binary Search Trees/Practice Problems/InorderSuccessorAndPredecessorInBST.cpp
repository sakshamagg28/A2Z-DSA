// Method 1: Search + Left/Right Subtree
// Time Complexity: O(H)
// Space Complexity: O(1)
// H = Height of the BST
// Standard Interview Solution

class Solution {
public:
    vector<int> succPredBST(TreeNode* root, int key) {
        int pred = -1, succ = -1;
        TreeNode* curr = root;

        // Search for the key while keeping track of possible predecessor and successor
        while (curr) {
            if (key < curr->data) {
                succ = curr->data;
                curr = curr->left;
            }
            else if (key > curr->data) {
                pred = curr->data;
                curr = curr->right;
            }
            else {
                break;
            }
        }

        // Find inorder predecessor (rightmost node of left subtree)
        if (curr->left) {
            TreeNode* node = curr->left;
            while (node->right)
                node = node->right;
            pred = node->data;
        }

        // Find inorder successor (leftmost node of right subtree)
        if (curr->right) {
            TreeNode* node = curr->right;
            while (node->left)
                node = node->left;
            succ = node->data;
        }

        return {pred, succ};
    }
};





// Method 2: Two BST Traversals
// Time Complexity: O(H)
// Space Complexity: O(1)
// H = Height of the BST

class Solution {
public:
    vector<int> succPredBST(TreeNode* root, int key) {
        int pred = -1, succ = -1;
        TreeNode* curr = root;

        // Find predecessor
        while (curr) {
            if (key > curr->data) {
                pred = curr->data;
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        curr = root;

        // Find successor
        while (curr) {
            if (key < curr->data) {
                succ = curr->data;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        return {pred, succ};
    }
};