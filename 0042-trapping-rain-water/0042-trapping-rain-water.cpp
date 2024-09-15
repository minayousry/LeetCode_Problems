class Solution {
public:
    int trap(vector<int>& height)
    {
        int length = height.size();
        
        if(length < 2)
        {
            return 0;
        }
        else
        {
            int left_ptr = 0;
            int right_ptr = length - 1;
            
            int max_left = height[left_ptr];
            int max_right = height[right_ptr];
            
            int trapped_water = 0;
            
            
            while(left_ptr < right_ptr)
            {
            
                if(max_left <= max_right)
                {
                    left_ptr++;
                    max_left = max(max_left,height[left_ptr]);
                    trapped_water += (max_left - height[left_ptr]);

                    
                }
                else
                {
                    right_ptr--;
                    max_right = max(max_right,height[right_ptr]);
                    trapped_water += (max_right - height[right_ptr]);

                    
                }
            }
            return trapped_water;
        }
    }
};
