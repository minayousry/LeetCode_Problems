#include <bits/stdc++.h>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> result;
        unordered_map<int,int> data;

        priority_queue<int> occurance2;
        
        
        for(int i=0;i<nums.size();++i)
        {
            data[nums[i]] +=1;
        }
        
        for(auto data_set:data)
        {
            occurance2.push(data_set.second);
        }

        while (k != 0)
        {
            for(auto data_set:data)
            {
                if(data_set.second == occurance2.top())
                {
                    result.push_back(data_set.first);
                    data.erase(data_set.first);
                    occurance2.pop();
                    k--;
                    break;
                }
                
            }
            
        }
        
        
        return result;
    }
};