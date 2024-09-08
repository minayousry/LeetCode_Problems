class Solution {
public:
    int characterReplacement(string s, int k) {
        int dict[26] = {0};
        int result = 0;
        int l = 0;
        int r = 0;
        int window_size = 0;
        int max_occurance = 0;
        int no_of_replacements = 0;

        for(r=0;r<s.size();++r)
        {
            dict[s[r] - 'A']++;

            window_size = r - l + 1;
            max_occurance = *(std::max_element(dict,dict+26));
            no_of_replacements = window_size - max_occurance;
                        
            if(no_of_replacements <= k)
            {
                result = max(result,window_size);
            }
            else
            {
                //Remove the leftmost character from the window
                dict[s[l] - 'A']--;
                l++;
            }
        }

        return result;

    }
};