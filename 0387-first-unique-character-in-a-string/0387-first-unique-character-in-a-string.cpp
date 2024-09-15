class Solution {
public:
    int firstUniqChar(string s)
    {
        int element_positions[28] = {0};
          
        for(int i=0;i<28;++i)
        {
            element_positions[i] = -1;
        }

        for(int i=0;i<s.size();++i)
        {

            if(element_positions[s[i] - 'a'] == -1)
            {
                
                element_positions[s[i] - 'a'] = i;
            }
            else
            {
                element_positions[s[i] - 'a'] = 100002;
            }
        }
        
        int min_val = 100001;
        
        for(int i=0;i<s.size();++i)
        {
            if(element_positions[s[i] - 'a'] >=0)
            {
                min_val = min(min_val,element_positions[s[i] - 'a']);
            }
            
        }
        
        if(min_val == 100001)
        {
            min_val = -1;
        }
        
        return min_val;
        
    }
};