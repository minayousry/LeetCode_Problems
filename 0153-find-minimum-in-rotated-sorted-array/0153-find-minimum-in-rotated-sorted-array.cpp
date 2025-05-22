class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int min_val = INT_MAX;

        while(start <= end)
        {
            int mid = start + (end - start)/2;

            if(nums[mid] < nums[start])  
            {

                min_val = min(min_val,nums[mid]);
                end = mid - 1;
            }
            else 
            {
                min_val = min(min_val,nums[start]);
                start = mid + 1;
            }
        }
        return min_val;
    }
};