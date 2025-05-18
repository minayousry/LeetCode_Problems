class Solution {
public:

    void backTrack(vector<int>& candidates,vector<int> &subset,int index, int target,set<vector<int>> &result)
    {
        if(target == 0)
        {
            result.insert(subset);
            return;
        }
        else if((target < 0) || (index >= candidates.size()))
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
        set<vector<int>> output;
        

        vector<int> subset;
        

        backTrack(candidates,subset,0,target,output);

        for(auto &arr:output)
        {
            res.emplace_back(arr);
        }
        return res;
    }
};