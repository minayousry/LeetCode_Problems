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

    int getDepth(TreeNode* root,int &res)
    {
        if(root == nullptr)
        {
            return 0;
        }
        else
        {
            int left_branch = getDepth(root->left,res);
            int right_branch = getDepth(root->right,res);

            res = max(res,left_branch + right_branch);
             
            return (1 + max(left_branch,right_branch));
        }
    }


    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        getDepth(root,res);
        return res;
    }
};