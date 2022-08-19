class Solution {
public:
    int pivotIndex(vector<int>& nums)
    {
        int ret = -1;
        long sum = 0;
        sum = accumulate(nums.begin(),nums.end(),sum);
        long left_sum = 0;
        
        for(int i=0;i<nums.size();++i)
        {
            if(left_sum == (sum - left_sum - nums[i]))
            {
                ret =  i;
                break;
            }
            left_sum+=nums[i];
        }
        
        return ret;

    }
};