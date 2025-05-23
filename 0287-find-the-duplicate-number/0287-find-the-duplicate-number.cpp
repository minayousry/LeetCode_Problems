class Solution {
public:

    
    int findDuplicate(vector<int>& nums) {
        
        int slow_ind = 0;
        int fast_ind = 0;

        //find first intersection
        do
        {
            slow_ind = nums[slow_ind];
            fast_ind = nums[nums[fast_ind]];
        }while(slow_ind != fast_ind);


        int slow2_ind = 0;

        while(slow2_ind != slow_ind)
        {
            slow2_ind = nums[slow2_ind];
            slow_ind = nums[slow_ind];
        }

        return slow_ind;


        return 0;
    }
};