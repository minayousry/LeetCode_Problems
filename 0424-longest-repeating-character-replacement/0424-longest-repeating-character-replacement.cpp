class Solution {
public:

    int characterReplacement(string s, int k) {
        
        vector<int> freq(26,0);

        int longest_substr = 0;

        int r = 0;
        int l = 0;
        int max_freq;
        int window_len;

        while( r < s.size())
        {
            freq[s[r] - 'A']++;

            window_len = r - l + 1;
            max_freq = *max_element(freq.begin(),freq.end());


            while((window_len - max_freq) > k)
            {
                freq[s[l] - 'A']--;
                l++;
                window_len = r - l + 1;
            }
            
            longest_substr = max(longest_substr,window_len);
            r++;
        }
        return longest_substr;
    }
};