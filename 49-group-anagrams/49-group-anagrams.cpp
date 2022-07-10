class Solution {
public:
    
     int getStrSize(string &str)
    {
        int len = 0;
        for(int j=0;j<str.size();++j)
        {
            len+=str[j];
        }
        return len;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> groups;
        string sorted;
        
        vector<string> group;
        unordered_map<string,vector<int>> data;
        
        int str_len;
        
        for(int i=0;i<strs.size();++i)
        {
            sorted = strs[i];
            sort(sorted.begin(),sorted.end());
            //str_len = getStrSize(strs[i]);

            data[sorted].push_back(i);
        }
        
        
        for(auto it = data.begin();it != data.end();++it)
        {
            group.clear();
            //cout<<it->first;
            
            for(int i= 0;i<data[it->first].size();++i)
            {
                group.push_back(strs[data[it->first][i]]);
            }
            
            groups.push_back(group);
        }
    
        
        
        
        return groups;
    }
};