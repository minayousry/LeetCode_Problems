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


    bool check_left(TreeNode* root,int node_val)
    {
        if(!root)
        {
            return true;
        }
        else if(root->val >= node_val)
        {
            return false;
        }
        else
        {
            return check_left(root->left,node_val) && check_left(root->right,node_val);
        }
    }

    bool check_right(TreeNode* root,int node_val)
    {
        if(!root)
        {
            return true;
        }
        else if(root->val <= node_val)
        {
            return false;
        }
        else
        {
            return check_right(root->left,node_val) && check_right(root->right,node_val);
        }
    }


    bool isValidBST(TreeNode* root) {

        bool result;

        if(root == nullptr)
        {
            return true;
        }
        else
        {
            result = check_left(root->left,root->val) && check_right(root->right,root->val);
            return result && isValidBST(root->left) && isValidBST(root->right);
        }
        
        
    }
};
