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

    void invertNodes(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        swap(root->left,root->right);
        invertNodes(root->left);
        invertNodes(root->right);
        

    }

    TreeNode* invertTree(TreeNode* root) {
        invertNodes(root);
        return root;

    }
};