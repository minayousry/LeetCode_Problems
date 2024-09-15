class Solution {
public:
    int firstBadVersion(int n)
    {
        
        int start = 0;
        int end = n;
        
        long mid;
        bool is_bad;
        int result = 0;
        
        while(start <= end)
        {
            mid = start + (end - start)/2;
            
            
            is_bad = isBadVersion((int)mid);
            
            if(is_bad)
            {
                end = mid - 1;
                result = mid;
            }
            else
            {
                start = mid + 1;
            }

            
            
        }
        return result;
        
    }
};