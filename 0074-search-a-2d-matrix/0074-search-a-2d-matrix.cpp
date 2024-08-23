class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int start = 0;
        int end = matrix.size()*matrix[0].size() - 1;

        bool result = false;
        int mid;
        int row,col;

        

        while(start <= end)
        {
            mid = start + (end - start)/2;

            row = mid/matrix[0].size();
            col = mid%matrix[0].size();

            if(matrix[row][col] < target)
            {
                start = mid + 1;
            }
            else if(matrix[row][col] > target)
            {
                end = mid - 1;
            }
            else
            {
                result = true;
                break;
            }
            

        }
        return result;
    }


};