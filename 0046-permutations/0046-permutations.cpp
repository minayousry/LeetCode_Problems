class Solution {
public:

    void backtrack(vector<int>& nums,vector<int>& perms,vector<bool> &used,vector<vector<int>> &res)
    {
        if(perms.size() == nums.size())
        {
            res.emplace_back(perms);
            return;
        }


        
        for(int i=0;i <nums.size();++i)
        {
            if(used[i] == false)
            {
                perms.push_back(nums[i]);
                used[i] = true;
                backtrack(nums,perms,used,res);
                perms.pop_back();
                used[i] = false; 
            }
            

        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> perms;
        vector<bool> used(nums.size(),false);

        backtrack(nums,perms,used,res);
        return res;
    }
};