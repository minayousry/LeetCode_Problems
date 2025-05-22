class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> dict;
        int l=0;
        int r = 0;

        int max_substr = 0;
        
        while(r < s.size())
        {
            dict[s[r]]++;
            
            while(dict[s[r]] > 1)
            {
                dict[s[l]]--;
                l++;
            }
            max_substr = max(max_substr,r - l + 1);
            r++;
        }
        return max_substr;
        
    }
};