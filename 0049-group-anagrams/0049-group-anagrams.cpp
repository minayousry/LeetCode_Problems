class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> dict;

       for(int i=0;i<strs.size();++i)
       {
            string temp(26,'0');
            for(int j=0;j<strs[i].size();++j)
            {
                temp[strs[i][j] - 'a'] +=1;
            }
            dict[temp].push_back(strs[i]);
       }

       for(auto it =dict.begin();it != dict.end();++it)
       {
            result.push_back(it->second);
       }
        
        return result;
    }
};