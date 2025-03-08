class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> result;
        
        unordered_map<int,int> occurances; 

        priority_queue<pair<int,int>> data;
        

        for(int i=0;i<nums.size();++i)
        {
            occurances[nums[i]]++;
        }

        for(auto it = occurances.begin();it != occurances.end();++it)
        {
            data.push({it->second, it->first});            
        }

        while(!data.empty())
        {
            if(k > 0)
            {
                result.push_back(data.top().second);
                data.pop();
                k--;
            }
            else
            {
                break;
            }
        }

        return result;
    }
};