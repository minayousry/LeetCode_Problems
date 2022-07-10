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
    
    TreeNode* invertTree(TreeNode* root)
    {
        TreeNode* left_node;
        TreeNode* right_node;
        
        if(root != nullptr)
        {
            left_node = root->left;
            right_node = root->right;
            
            root->left = right_node;
            root->right = left_node;
            
            invertTree(root->left);
            invertTree(root->right);
            
            
        }
        
        return root;
            
        
    }
};