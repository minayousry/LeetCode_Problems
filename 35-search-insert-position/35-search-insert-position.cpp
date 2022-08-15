class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int result = nums.size();
        
        set<int> nums2(nums.begin(),nums.end());
        
        auto it = nums2.lower_bound(target);
        
        if(it != nums2.end())
        {
            result = distance(nums2.begin(),it);
        }
        
        return result;
        
    }
};