class Solution {
public:

    void dfs(vector<int>& nums,int i,vector<int> &cur,vector<vector<int>> &res)
    {
        if(i >= nums.size())
        {
            res.emplace_back(cur);
            return;
        }

        cur.emplace_back(nums[i]);
        dfs(nums,i+1,cur,res);

        cur.pop_back();
        dfs(nums,i+1,cur,res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums,0,cur,res);

        return res;

        
    }
};