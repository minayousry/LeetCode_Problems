class Solution {
public:
    bool judgeSquareSum(int c)
    {
        
        bool is_square_sum = false;
        unordered_map<int,bool> dict;
        long int square_num = 0;
        
         if(c < 3)
            return true;
        
        dict[0] = true; 
        for(int i=1;i<c;++i)
        {
             square_num = pow(i,2);
            
             if(square_num <= static_cast<long int>(c))
             {
                if((square_num == (c - square_num)) || (dict.find(c - square_num) != dict.end()))
                {
                    is_square_sum = true;
                    break;
                }
                dict[square_num] = true;    
             }
             else
             {
                 break;
             }         
        }
   
        return is_square_sum;
    }

};