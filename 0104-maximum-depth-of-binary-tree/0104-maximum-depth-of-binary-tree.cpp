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

    int getNodesNo(TreeNode* root)
    {
        static int res = 0; 

        if(root)
        {

            return 1 + max(getNodesNo(root->left),getNodesNo(root->right));
        }
        else
        {
            return 0;
        }
    }
    int maxDepth(TreeNode* root) {

        return getNodesNo(root);
         
    }
};