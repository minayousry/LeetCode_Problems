class Solution {
public:

    void backTrack(vector<int>& candidates,vector<int> &subset,int index,int sum, int target,vector<vector<int>> &result)
    {
        if(sum == target)
        {
            result.push_back(subset);
            return;
        }
        else if((index >= candidates.size()) || (sum > target))
        {
            return;
        }

        //Include the element
        subset.push_back(candidates[index]);
        backTrack(candidates,subset,index,sum + candidates[index],target,result);
        
        //exclude the element
        subset.pop_back();
        backTrack(candidates,subset,index + 1,sum,target,result);


    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;

        vector<int> subset;
        
        int sum = 0;

        backTrack(candidates,subset,0,sum,target,res);
        return res;
    }
};