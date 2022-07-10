class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if(s.size() != t.size())
        {
            return false;
        }
        else if(s == t)
        {
            return true;
        }
        else
        {
            int x = 0;
            int y=0;
            
            map<char,int> data1;
            map<char,int> data2;
            
            //sort(s.begin(),s.end());
            //sort(t.begin(),t.end());
            
            for(int i=0;i<s.size();++i)
            {
                data1[s[i]] +=1;
                data2[t[i]] +=1;
                
            }
            
            //auto keys2 = data2.keys();
            
            for(auto element:data1)
            {
                
                if(data2.find(element.first) != data2.end())
                {
                    if(data1[element.first] != data2[element.first])
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            
            return true;


            
        }
    }
};