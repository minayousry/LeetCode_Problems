class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> s1_seen(26, 0);
        vector<int> s2_seen(26, 0);

        for (char c : s1) {
            s1_seen[c - 'a']++;
        }

        int l = 0;

        for (int r = 0; r < s2.size(); ++r) {
            
            s2_seen[s2[r] - 'a']++;

            // If window size > s1.size(), shrink from left
            if (r - l + 1 > s1.size()) {
                s2_seen[s2[l] - 'a']--;
                l++;
            }

            if ((r - l + 1) == s1.size() && s1_seen == s2_seen) {
                return true;
            }
        }

        return false;
    }
};
