class Solution {
public:
    bool isPalindrome(string s) 
    {
        //queue<char> q1;
        //vector<char> q2;
        
        
        bool status = true;

        
        if(s.size() <= 1)
        {
            status = true;
        }
        else
        {
            unsigned char data[255] = {0};
        
            for(unsigned char i = '0';i<='9';++i)
            {
                data[i] = 1;
            }
        
        
            for(unsigned char i = 'a';i<='z';++i)
            {
                data[i] = 1;
            }
        
            for(unsigned char i = 'A';i<='Z';++i)
            {
                data[i] = 1;
            }
            
            int l = 0;
            int r = s.size() - 1;
        
            while(l < r)
            {
                while((l < r) && (data[s[l]] == 0u))
                {
                    l++;
                }
                
                while((l < r) && (data[s[r]] == 0u))
                {
                    r--;
                }
                
                if(s[l] > 90)
                {
                    s[l] -= 32;
                }
                
                if(s[r] > 90)
                {
                    s[r] -= 32;
                }

                if(s[r] != s[l])
                {
                    status = false;
                    break;
                }
                l++;
                r--;
            }
        }
        return status;
        
    }
};