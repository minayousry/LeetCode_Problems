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
    
    int DFS(TreeNode* root)
    {
        if(root == nullptr)
        {
            return -1;
        }
        
        int left_height = DFS(root->left);
        int right_height = DFS(root->right);
            
        return max(left_height,right_height) + 1;
        

    }
    
    bool isBalanced(TreeNode* root)
    {

        bool is_balanced = true;

        queue<TreeNode *> elements;
        
        elements.push(root);
        TreeNode *element;
        int counter_right;
        int counter_left;
        
        while(!elements.empty())
        {
            counter_right = 0;
            counter_left = 0;
            
            element = elements.front();
            elements.pop();
            
            if(element != nullptr)
            {
                counter_left = DFS(element->left);
                counter_right = DFS(element->right);
                
                elements.push(element->left);
                elements.push(element->right);
                
            }
            
            int height = abs(counter_left - counter_right);


            if(height > 1)
            {
                is_balanced = false;
                break;
            }
        }        
        return is_balanced;
    }
};