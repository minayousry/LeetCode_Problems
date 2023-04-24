class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> result;
        unordered_map<int,int> data;
        
        for(int i=0;i<nums.size();++i)
        {
            if(data.find(target - nums[i]) != data.end())
            {
                result.push_back(i);
                result.push_back(data[target-nums[i]]);
                break;
            }
            else
            {
                data[nums[i]] = i;
            }
        }
        return result;
    }
};