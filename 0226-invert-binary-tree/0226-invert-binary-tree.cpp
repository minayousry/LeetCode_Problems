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

    void swapDfs(TreeNode** root)
    {
        TreeNode* temp;
        if(*root)
        {
            temp = (*root)->left;
            (*root)->left = (*root)->right;
            (*root)->right = temp;

            swapDfs(&((*root)->left));
            swapDfs(&((*root)->right));
        }
        
    }
    TreeNode* invertTree(TreeNode* root) {
        
        TreeNode* start = root;
        if(root)
        {
            swapDfs(&root);
        }
        return start;
    }
};