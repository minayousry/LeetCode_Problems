class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> result;
        unordered_map<int,int> data;
        
        for(int i=0;i<numbers.size();++i)
        {
            if(data.find(target - numbers[i]) != data.end())
            {
                result.push_back(i);
                result.push_back(data[target-numbers[i]]);
                break;
            }
            else
            {
                data[numbers[i]] = i;
            }
        }
        
        sort(result.begin(),result.end());
        
        for(auto i = 0;i<result.size();++i)
        {
            result[i]++;
        }
        
        return result;
        
    }
};