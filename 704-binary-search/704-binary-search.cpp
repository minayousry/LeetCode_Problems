class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int result = -1;
        
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        
        while(start <= end)
        {
            mid = ((start + end)>>1);
            
            if(nums[mid] < target)
            {
                start = mid + 1;
                
            }
            else if(nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                result = mid;
                break;
            }
        }
        return result;
    }
};