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
        vector<vector<int>> result;
        queue<TreeNode*> data;

        if(root != nullptr)
        {
            data.push(root);
        }
        
        while(!data.empty())
        {
            TreeNode* node = data.front();

            vector<int> found_data;
            int queue_size = data.size(); 
            for(int i=0;i<queue_size;++i)
            {
                TreeNode* node = data.front();
                data.pop();
                found_data.push_back(node->val);
                
                if(node->left)
                {
                    data.push(node->left);
                }

                if(node->right)
                {
                    data.push(node->right);
                }
            }
            result.push_back(found_data);
            
        }
        return result;

    }
};