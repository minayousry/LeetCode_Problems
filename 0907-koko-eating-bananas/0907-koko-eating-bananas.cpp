class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(),piles.end());
        int min_h = end;

        int mid;

        while(start <= end)
        {
            mid = start + (end - start)/2;

            int total_hrs = 0;



            for(auto &pile:piles)
            {
                total_hrs += ((pile + mid - 1)/ mid);
                if(total_hrs > h)
                {
                    break;
                }
            }

            if(total_hrs <= h)
            {
                min_h = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return min_h;

    }
};