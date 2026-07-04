/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


/**
 * ==========================================================
 * Approach 1 : BFS + Level Order
 * ----------------------------------------------------------
 * Time  : O(N)
 * Space : O(N)
 *
 * Serialize:
 * Store nodes level-wise.
 * Use "#" for null nodes.
 *
 * Deserialize:
 * Read values level-wise and reconstruct children.
 * ==========================================================
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if(!root) return "";

        string s;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            TreeNode* node = q.front();
            q.pop();

            if(node){
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
            else{
                s += "#,";
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data.empty()) return nullptr;

        stringstream ss(data);
        string val;

        getline(ss, val, ',');

        TreeNode* root = new TreeNode(stoi(val));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            TreeNode* node = q.front();
            q.pop();

            // Left child
            getline(ss, val, ',');

            if(val != "#"){
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }

            // Right child
            getline(ss, val, ',');

            if(val != "#"){
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }

        return root;
    }
};



/**
 * ==========================================================
 * Approach 2 : DFS (Preorder)
 * ----------------------------------------------------------
 * Time  : O(N)
 * Space : O(N)
 *
 * Serialize using preorder traversal.
 * Store "#" for null nodes.
 *
 * Deserialize recursively.
 * ==========================================================
 */

class Codec {
public:

    void preorder(TreeNode* root, string &s){

        if(!root){
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";

        preorder(root->left, s);
        preorder(root->right, s);
    }

    TreeNode* build(stringstream &ss){

        string val;
        getline(ss, val, ',');

        if(val == "#")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(val));

        root->left = build(ss);
        root->right = build(ss);

        return root;
    }

    string serialize(TreeNode* root) {

        string s;

        preorder(root, s);

        return s;
    }

    TreeNode* deserialize(string data) {

        stringstream ss(data);

        return build(ss);
    }
};