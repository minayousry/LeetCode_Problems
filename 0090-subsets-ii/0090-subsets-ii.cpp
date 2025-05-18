class Solution {
public:

    void backtrack(vector<int> &nums,int i,vector<int> &subset,set<vector<int>> &output)
    {
           
        if( i >= nums.size())
        {
            output.insert(subset);
            return;
        }
        else if(subset.size() > nums.size())
        {
            return;
        }

        //include new element
        subset.push_back(nums[i]);
        backtrack(nums,i+1,subset,output);

        subset.pop_back();
        backtrack(nums,i+1,subset,output);
    } 

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;

        set<vector<int>> output;
        
        sort(nums.begin(),nums.end());
        backtrack(nums,0,subset,output);

        for(auto &arr:output)
        {
            res.push_back(arr);
        }

        return res;
    }
};