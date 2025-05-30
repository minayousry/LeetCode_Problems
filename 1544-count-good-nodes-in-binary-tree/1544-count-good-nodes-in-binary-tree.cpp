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

    void countNodes(TreeNode* root,int compare_val,int &result)
    {
        if(!root)
        {
            return;
        }
        
        if(root->val >= compare_val)
        {
            result+= 1;
        }

        countNodes(root->left, max(root->val,compare_val),result);
        countNodes(root->right, max(root->val,compare_val),result);

    }

    int goodNodes(TreeNode* root) {

        int result = 0;
        countNodes(root,INT_MIN,result);
        return result;
 
    }
};
