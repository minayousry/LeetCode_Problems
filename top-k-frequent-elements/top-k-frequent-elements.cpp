#include <bits/stdc++.h>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> result;
        unordered_map<int,int> data;
        bool end = false;

        vector<vector<int>> mpps(nums.size()+1);
        
        
        for(int i=0;i<nums.size();++i)
        {
            data[nums[i]] +=1;
        }

        for(auto data_set:data)
        {
            mpps[data_set.second].push_back(data_set.first);
        }

        for(int i= (mpps.size() - 1);i>=0;--i)
        {
            for(int j=0;j<mpps[i].size();++j)
            {
                result.push_back(mpps[i][j]);
                k--;
                if(k == 0)
                {
                    end = true;
                    break;
                }
            }
            if(end)
            {
                break;
            }
        }      
        
        return result;
    }
};