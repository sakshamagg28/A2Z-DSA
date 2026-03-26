/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{	
	public:
		vector<int> floorCeilOfBST(TreeNode* root,int key){
			//your code goes here
            TreeNode* node = root;
            int floor = -1, ceil = -1;

            while (node){
                if (key == node->data){
                    return {node->data, node->data};
                }
                else if (key > node->data){
                    floor = node->data;
                    node = node->right;
                }
                else {
                    ceil = node->data;
                    node = node->left;
                }
            }
            return {floor, ceil};
		}
};