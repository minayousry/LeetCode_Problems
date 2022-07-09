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
    
    bool DFS(TreeNode* root,int &height)
    {
        if(root == nullptr)
        {
            height = 0;
            return true;
        }
        else
        {
            int left_height = 0;
            int right_height = 0;
            
            bool left_status = DFS(root->left,left_height);
            
            if(left_status == false)
                return false;
            
            bool right_status = DFS(root->right,right_height);
            
            if(right_status == false)
                return false;
         
            
            if(abs(left_height - right_height) > 1)
                return false;
            else
                height = max(left_height,right_height) + 1;
                return true;

        }
        

    }
    
    bool isBalanced(TreeNode* root)
    {

        bool is_balanced = true;    
        int height = 0;
        is_balanced = DFS(root,height);
 
        return is_balanced;
    }
};