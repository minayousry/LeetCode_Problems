class Solution {
public:
    bool isAnagram(string s, string t)
    {
        int s_size = s.size();
        int t_size = t.size();

        bool result = true;


        
        
        if(s_size == t_size)
        {
            unsigned int data1[26] = {0};
            unsigned int data2[26] = {0};
             

            for(int i=0;i<s_size;++i)
            {
                data1[s[i] - 'a'] += 1;
                data2[t[i] - 'a'] += 1;
            }

            for(int i=0;i<26;++i)
            {
                if(data1[i] != data2[i])
                {
                    result = false;
                    break;
                }

            }
        }
        else
        {
            result = false;
        }

        return result;
        
    }
};