#include <bits/stdc++.h>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> result;
        unordered_map<int,int> count;
        bool end_loop = false;
        
        vector<vector<int>> freq(nums.size() + 1);
        
        for(auto &num:nums)
        {
            count[num] +=1;
        }

        for(auto &elm:count)
        {
            freq[elm.second].emplace_back(elm.first);
        }

        for(auto rit = freq.rbegin();(!end_loop && (rit != freq.rend()));++rit)
        {
            for(int i=0;i<rit->size();++i)
            {
                result.emplace_back((*rit)[i]);
                k--;
                if(k == 0)
                {
                    end_loop = true;
                    break;
                }
            }
            
        }


        return result;
    }
};