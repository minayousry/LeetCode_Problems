class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        int w1_size = word1.size();
        int w2_size = word2.size();

        string total = "";

        int i = 0;
        int j = 0;
        
        while((i < w1_size) || (j < w2_size))
        {
            if(i < w1_size)
            {
                total += word1[i];
                i++;
            }

            if(j < w2_size)
            {
                total += word2[j];
                j++;
            }
        }

        return total;
        
    }
};