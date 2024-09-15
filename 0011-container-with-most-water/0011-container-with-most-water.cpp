class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = int(height.size()) - 1;
        int area = min(height[left],height[right]) *(right - left);
        int max_area = 0;

        if(height.size() == 2)
        {
            max_area = area;
        }
        else
        {

            while (left < right) {

                area = min(height[left],height[right]) *(right - left);
                cout<<area<<endl;

                if(area > max_area)
                {
                    max_area = area;
                } 

                if(height[left] < height[right])
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return max_area;
        
    }
};