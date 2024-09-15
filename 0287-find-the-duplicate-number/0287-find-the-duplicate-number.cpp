class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        unordered_set<int> data;
        int set_len = data.size();

        for(auto &num:nums)
        {
            data.insert(num);
            if(data.size() == set_len)
            {
                return num;
            }
            else
            {
                set_len = data.size();
                
            }
        }
        return nums[0];
    }
};