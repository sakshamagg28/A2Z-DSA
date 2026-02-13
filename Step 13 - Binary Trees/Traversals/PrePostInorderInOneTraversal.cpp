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
		vector<vector<int> > treeTraversal(TreeNode* root){
			//your code goes here
			vector<vector<int>> result;
			result.push_back(inorderTraversal(root));
			result.push_back(preorderTraversal(root));
			result.push_back(postorderTraversal(root));

			return result;
		}

		vector<int> preorderTraversal(TreeNode* root){
			if (!root) return {};
			vector<int> result;

			vector<int> left = preorderTraversal(root->left);
			vector<int> right = preorderTraversal(root->right);

			result.push_back(root->data);
			result.insert(result.end(), left.begin(), left.end());
			result.insert(result.end(), right.begin(), right.end());

			return result;
		}

		vector<int> postorderTraversal(TreeNode* root){
			if (!root) return {};
			vector<int> result;

			vector<int> left = postorderTraversal(root->left);
			vector<int> right = postorderTraversal(root->right);

			result.insert(result.end(), left.begin(), left.end());
			result.insert(result.end(), right.begin(), right.end());
			result.push_back(root->data);

			return result;
		}

		vector<int> inorderTraversal(TreeNode* root){
			if (!root) return {};
			vector<int> result;

			vector<int> left = inorderTraversal(root->left);
			vector<int> right = inorderTraversal(root->right);

			result.insert(result.end(), left.begin(), left.end());
			result.push_back(root->data);
			result.insert(result.end(), right.begin(), right.end());

			return result;
		}
};