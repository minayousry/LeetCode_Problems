class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {

        
        if(nums.size() < 2)
        {
            return nums.size();
        }
        else
        {
            bool start = false;
            set<int> data(nums.begin(),nums.end());
            int counter = 1;
            int old = *data.begin();
            
            int max = 1;
            
            for(auto it=next(data.begin(),1);it != data.end();++it)
            {

                if(abs(*it - old) == 1u)
                {
                    counter++;  
                }
                else
                {
   
                    counter = 1;
                }
                
                if(max < counter)
                {
                    max = counter;    
                }
 
                old = *it;
                
            }
            return max;
        }
        
        
    }
};