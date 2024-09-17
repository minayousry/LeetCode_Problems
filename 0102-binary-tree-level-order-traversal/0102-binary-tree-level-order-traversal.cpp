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

    
    vector<vector<int>> levelOrder(TreeNode* root) {

        queue<TreeNode*> data;
        vector<vector<int>> result;
        
        if(root == nullptr)
        {
            return result;
        }
        
        data.push(root);

        while(!data.empty())
        {
            vector<int> elms;
            int len = data.size();
            for(int i=0;i<len;i++)
            {
                auto elm = data.front();
                data.pop();
                elms.push_back(elm->val);

                if(elm->left)
                {
                    data.push(elm->left);
                }

                if(elm->right)
                {
                    data.push(elm->right);
                }

            }
            
            result.push_back(elms);
            
        }

        return result;
        
    }
};
