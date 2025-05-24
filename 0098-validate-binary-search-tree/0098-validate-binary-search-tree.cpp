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

    bool checkValidity(TreeNode* root,long left,long right)
    {
        if(root == nullptr)
        {
            return true;
        }
        else if(left >= root->val || right <= root->val)
        {
            return false;
        }
        else
        {
            return checkValidity(root->left,left,root->val) && checkValidity(root->right,root->val,right);

        }

    }

    bool isValidBST(TreeNode* root) {
        
          return checkValidity(root,LONG_MIN,LONG_MAX);
    }


};