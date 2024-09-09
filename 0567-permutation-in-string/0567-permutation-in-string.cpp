class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length()) {
            return false;
        }
        
        int dict1[26] = {0};
        int dict2[26] = {0};
        bool result = false;

        for(int i =0;i<s1.size();++i)
        {
            dict1[s1[i] - 'a']++;
        }

        int l = 0;
        int window_size = 0;

        for(int r = 0;r<s2.size();++r)
        {
            dict2[s2[r] - 'a']++;

            window_size = r - l + 1;

            if(window_size == s1.size())
            {
                if(equal(begin(dict1),end(dict1),begin(dict2)))
                {
                    result = true;
                    break;
                }
                else
                {
                    dict2[s2[l] - 'a']--;
                    l++;
                }
            }
        }

        return result;


    }
};