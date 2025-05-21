#include <algorithm>
#include <map>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> triplets;

        if(nums.size() == 3)
        {
            if(nums[0] + nums[1] + nums[2] == 0)
            {
                triplets.push_back({nums[0],nums[1],nums[2]});

            }
            return triplets;
        }

        std::sort(nums.begin(),nums.end());
        

        int l = 0;
        int r = nums.size() - 1;

        int first_num;
        int second_num;
        int third_num;
        int sum;
        
        for(int i=0;i<nums.size() - 2;++i)
        {
            // Skip duplicates for nums[i]
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            first_num = nums[i];
            l = i + 1;
            r = nums.size() - 1;

            while(l < r)
            {
            
                second_num = nums[l];
                third_num = nums[r];

                sum = first_num + second_num + third_num;
                
                
                if(sum == 0)
                {
                    triplets.push_back({first_num,second_num,third_num});
                    l++;
                    r--;
                    // Skip duplicates for nums[l] and nums[r]
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
                else if(sum > 0)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }

        }

        return triplets;

    }
};