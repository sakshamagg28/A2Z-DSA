/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
		vector<int> succPredBST(TreeNode* root,int key){
			//your code goes here
            int succ = -1, pred = -1;
            int parent;
            while (root && root->data != key){
                parent = root->data;
                if (root->data > key) {
                    succ = root->data;
                    root = root->left;
                }
                else {
                    pred = root->data;
                    root = root->right;
                }
            }
            if (root->left){
                TreeNode* temp = root->left;
                while(temp->right) temp = temp->right;
                pred = temp->data;
            }
            if (root->right){
                TreeNode* temp = root->right;
                while(temp->left) temp = temp->left;
                succ = temp->data;
            }

            return {pred, succ};
		}
};