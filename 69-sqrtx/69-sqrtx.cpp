class Solution {
public:
    int mySqrt(int x) 
    {
        
        if(x < 2)
            return x;
        
        int result;
        int start = 1;
        int end = x/2;
        int mid;
   
        while(start <= end)
        {
            mid = start + (end - start)/2; //1
            

            if(mid <= x/mid)
            {
                 result = mid;
                 start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
                
        }
        return result;
    }
};