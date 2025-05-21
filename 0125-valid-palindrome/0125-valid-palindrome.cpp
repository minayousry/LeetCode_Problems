#include<cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        bool result = true;
        
        if(s.size() <= 1)
        {
            return s.size();
        }

        int l = 0;
        int r = s.size() - 1;

        while(l < r)
        {
            while(l < r && !isalnum(s[l]))
            {
                l++;
            }

            while(l < r && !isalnum(s[r]))
            {
                r--;
            }

            if(std::tolower(s[l]) != std::tolower(s[r]))
            {
                result = false;
                break;
            }
            l++;
            r--;
        }

        return result;
    }
};