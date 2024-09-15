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
    
    void invertNode(TreeNode* root)
    {
        if(root)
        {
            TreeNode* temp_node = root->left;
            root->left = root->right;
            root->right = temp_node;
            invertNode(root->left);
            invertNode(root->right);
        }

    }

    TreeNode* invertTree(TreeNode* root) {

        if(root == nullptr)
        {
            return nullptr;
        }

        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;


    }
};