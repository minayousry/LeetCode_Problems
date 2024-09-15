class Solution {
public:


    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());

        int left = 0;
        int right = int(nums.size()) - 1;
        vector<vector<int>> ans;
        int sum;
        int found_index;
        int target;

        while (left < right) {
            // do some logic here with left and right
            sum = nums[left] + nums[right];
            target = 0 - sum;
            auto it = std::find(&nums[left+1],&nums[right - 1],target);
            auto end = nums.end();
            
            if (it != 0)
            {
                ans.push_back({nums[left],*it,nums[right]});
                left++;
            }
            else
            {
                auto it2 = upper_bound(&nums[left+1],&nums[right - 1],target);
                if(it2 != nums.end())
                {
                    left++;
                }
                else
                {
                    right--;
                }

            }

        }

        return ans;
        
    }
};