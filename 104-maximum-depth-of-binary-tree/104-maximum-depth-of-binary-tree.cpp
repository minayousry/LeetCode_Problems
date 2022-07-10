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
    int maxDepth(TreeNode* root)
    {
        
        queue<TreeNode*> elements;
        TreeNode* first_elemet;
        int level_num = 0;
        
        if(root != nullptr)
        {
            elements.push(root);
        }
        
        while(!elements.empty())
        {
            int list_size = elements.size();
            
            for(int i=0;i<list_size;++i)
            {
                first_elemet = elements.front();
                elements.pop();
            
                if(first_elemet->left != nullptr)
                {
                    elements.push(first_elemet->left);
                }
            
                if(first_elemet->right != nullptr)
                {
                    elements.push(first_elemet->right);
                }
            }
            level_num += 1;
            
        }
        return level_num;
        
    }
};