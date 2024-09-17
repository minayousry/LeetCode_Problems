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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> result;
        queue<TreeNode*> data;

        if(root)
        {
            data.push(root);
            result.push_back(root->val);

            while(!data.empty())
            {
                int len = data.size();
                stack<int> vals;
                for(int i=0;i<len;++i)
                {
                    auto elm = data.front();
                    data.pop();

                    if(elm->left)
                    {
                        data.push(elm->left);
                        vals.push(elm->left->val);
                    }

                    if(elm->right)
                    {
                        data.push(elm->right);
                        vals.push(elm->right->val);
                    }
                }
                
                if(vals.size() > 0)
                {
                    result.push_back(vals.top());
                }
                
            }
        }
        

        return result;
        
    }
};
