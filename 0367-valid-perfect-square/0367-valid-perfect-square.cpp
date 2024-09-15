class Solution {
public:
    bool isPerfectSquare(int num)
    {
        bool status = false;
        
         if(num == 1)
             return true;
         else if(num < 4)
            return false;
        
        int start = 1;
        int end = num/2;
        int mid;

        while(start <= end)
        {
            mid = start + (end - start)/2; //1


            if(((float)mid - ((float)num/(float)mid)) == 0.0)
            {
                 status = true;
                 break;
            }
            else if(mid < num/mid)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
                
        }

        return status;
    }
        
};