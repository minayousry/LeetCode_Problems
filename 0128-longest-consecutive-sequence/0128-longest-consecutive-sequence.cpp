class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int result = 0;

        unordered_set<int> my_set(nums.begin(),nums.end());



        for(auto &num:my_set)
        {
            auto find_it = my_set.find(num - 1);

            if (find_it == my_set.end())
            {
                int i = 1;

                while(my_set.find(num + i) != my_set.end())
                {
                    ++i;
                }
                result = max(result,i);

            }
        }

        return result;
        
    }
};
