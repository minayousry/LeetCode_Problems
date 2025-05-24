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

    bool isSameTree(TreeNode* t1, TreeNode* t2)
    {
        if(!t1 && !t2)
        {
            return true;
        }
        else if(!t1 || !t2)
        {
            return false;
        }
        else if(t1->val != t2->val)
        {
            return false;
        }
        else
        {
            return isSameTree(t1->left,t2->left) && isSameTree(t1->right,t2->right); 
        }
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool result = false;

        if(!root && !subRoot)
        {
            return true;
        }
        else if(!subRoot)
        {
            return true;
        }
        else if(!root)
        {
            return false;
        }
        else if(root->val == subRoot->val)
        {
            if(isSameTree(root,subRoot))
            {
                return true;
            }
        }
        
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        
    }
};