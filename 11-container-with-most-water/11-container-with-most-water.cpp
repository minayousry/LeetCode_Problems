class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int length = height.size();
        
        if(length == 0)
        {
            return 0;
        }
        else if(length == 1)
        {
            return height[0];
        }
        else
        {
            int left_ptr = 0;
            int right_ptr = length - 1;
            
            int max_area = 0;
            int area = 0;
            
            
            
            while(left_ptr  < right_ptr)
            {
                area = (right_ptr - left_ptr)*min(height[left_ptr],height[right_ptr]);
                
                max_area = max(area,max_area);
                
                if(height[left_ptr] < height[right_ptr])
                {
                    left_ptr++;
                }
                else
                {
                    right_ptr--;
                }

                
            }
            return max_area;
        }
    }
};