class Solution {
public:
    bool judgeSquareSum(int c)
    {
        bool is_square_sum = false;
        
        long int left_ptr = 0;
        long int right_ptr = sqrt(c);
        long long int sum;
        
        while(left_ptr<=right_ptr)
        {
            sum = (left_ptr * left_ptr) + (right_ptr * right_ptr);
            
            if(sum == static_cast<long int>(c))
            {
                return true;
            }
            else if(sum < static_cast<long int>(c))
            {
                left_ptr++;
            }
            else
            {
                right_ptr--;
            }
        }
        
        
        return is_square_sum;
    }

};