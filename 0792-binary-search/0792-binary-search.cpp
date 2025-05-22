class Solution {
public:
    int search(vector<int>& nums, int target) {
        int found_ind = -1;
        int start = 0;
        int end = nums.size() - 1;
        int mid;

        while(start <= end)
        {
            mid = start + (end - start)/2;

            if(nums[mid]  == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return found_ind;
    }
};