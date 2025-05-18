class Solution {
public:

    void backTrack(vector<int>& candidates,vector<int> &subset,int index, int target,vector<vector<int>> &result)
    {
        if(target == 0)
        {
            result.push_back(subset);
            return;
        }
        else if((index >= candidates.size()) || (target < 0))
        {
            return;
        }

        //Include the element
        subset.push_back(candidates[index]);
        backTrack(candidates,subset,index,target - candidates[index],result);
        
        //exclude the element
        subset.pop_back();
        backTrack(candidates,subset,index + 1,target,result);


    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;

        vector<int> subset;
        
        int sum = 0;

        backTrack(candidates,subset,0,target,res);
        return res;
    }
};