class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int max_pile = static_cast<int>(*(std::max_element(piles.begin(),piles.end())));

        unsigned long int sum = 0;

        int rate;

        int start = 1;
        int end = max_pile;

        int result = max_pile;

        while(start<=end)
        {
            rate = start + (end - start)/2;
            
            sum = 0; 
            for(auto &pile:piles)
            {
                sum += (pile + rate - 1) / rate;;

            }

            if(sum <= h)
            {
                result = rate;
                end = rate - 1;
            }
            else
            {
                start = rate + 1;
            }

        }

        return result;

        
    }
};