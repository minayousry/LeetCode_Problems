class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> found_indices;

        int l = 0;
        int r = numbers.size() - 1;
        int sum;
        while(l < r)
        {
            sum = numbers[l] + numbers[r];

            if(sum == target)
            {
                found_indices.emplace_back(l + 1);
                found_indices.emplace_back(r + 1);
                break;
            }
            if(sum < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        return found_indices;
    }
};