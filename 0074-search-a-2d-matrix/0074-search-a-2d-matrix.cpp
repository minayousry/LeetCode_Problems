class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int start_x = 0;
        int end_x = matrix.size() - 1;
        int mid_x;
        bool is_found = false;
        int row_size = matrix[0].size() - 1;

        while(start_x <= end_x)
        {
            mid_x = start_x + (end_x - start_x)/2;

            if(target >=  matrix[mid_x][0] && target <=  matrix[mid_x][row_size])
            {
                int start_y = 0;
                int end_y = row_size;
                int mid_y;
                while(start_y <= end_y)
                {
                    mid_y = start_y + (end_y - start_y)/2;

                    if(matrix[mid_x][mid_y] == target)
                    {
                        is_found = true;
                        break;
                    }
                    else if( target < matrix[mid_x][mid_y])
                    {
                        end_y = mid_y - 1;
                    }
                    else
                    {
                        start_y = mid_y + 1;
                    }

                }
                break;
            }
            else if(target < matrix[mid_x][0])
            {
                end_x = mid_x - 1;
            }
            else
            {
                start_x = mid_x + 1;
            }
        }
        return is_found;
    }
};