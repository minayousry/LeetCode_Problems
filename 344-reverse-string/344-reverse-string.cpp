class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int final_index;
        int temp;
        for(int i=0;i<s.size()/2;++i)
        {
            final_index = s.size() - 1 - i;
            temp = s[i]; 
            s[i] = s[final_index];
            s[final_index] = temp;
        }
        
        
    }
};