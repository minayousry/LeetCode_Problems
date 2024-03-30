class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        int w1_size = word1.size();
        int w2_size = word2.size();
        int i = 0;
        string total = "";

        int min_size = std::min(w1_size,w2_size);
        
        while(i < min_size)
        {
            if(i < w1_size)
            {
                total += word1[i];
            }

            if(i < w2_size)
            {
                total += word2[i];
            }
            i++;
        }

        if(min_size == w2_size)
        {
            total += word1.substr(min_size);
        }
        else
        {
            total += word2.substr(min_size);
        }



        return total;
        
    }
};