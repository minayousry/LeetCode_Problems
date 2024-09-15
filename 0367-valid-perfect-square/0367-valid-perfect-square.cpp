class Solution {
public:
    bool isPerfectSquare(int num)
    {
        if (num == 1)
            return true;
        else if (num < 4)
            return false;

        int start = 1;
        int end = num;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            // To avoid overflow, compare using division
            if (mid == num / mid && num % mid == 0)
            {
                return true;
            }
            else if (mid < num / mid)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return false;
    }
};
