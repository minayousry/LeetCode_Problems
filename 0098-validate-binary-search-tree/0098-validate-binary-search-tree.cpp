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

        bool result = true;

        queue<tuple<TreeNode*,long,long>> data;

        if(root)
        {
            data.push(make_tuple(root,LONG_MIN,LONG_MAX));
        }
        
        while(!data.empty())
        {
            auto [elm,left_limit,right_limit] = data.front();
            data.pop();

            if((left_limit >= elm->val) || (right_limit <= elm->val))
            {
                return false;
            } 

            if(elm->left)
            {
                data.push(make_tuple(elm->left,left_limit,elm->val));
            }

            if(elm->right)
            {
                data.push(make_tuple(elm->right,elm->val,right_limit));
            }
        }
        return true;
        
        
    }
};
