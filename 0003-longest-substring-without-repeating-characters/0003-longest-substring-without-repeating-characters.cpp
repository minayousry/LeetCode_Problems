class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int l,r;
        l = 0;
        r = 0;
        int max_len = 0;
        unordered_map<char,int> dict;

        if(s.size() <= 1)
        {
            return s.size();
        }

        while(r < s.size())
        { 
            if(dict.find(s[r]) != dict.end() && dict[s[r]] >= l)
            {
                l = dict[s[r]] + 1;   
            }
            max_len = max(max_len, (r - l + 1));
            dict[s[r]] = r;
            r++;
        }
        return max_len;
        
    }
};