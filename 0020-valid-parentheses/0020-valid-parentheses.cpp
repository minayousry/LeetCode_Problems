class Solution {
public:
    bool isValid(string s)
    {
        stack<char> data;
        bool result = true;

        for(int i=0;i<s.size();++i)
        {
            switch(s[i])
            {
                case '(':
                case '[':
                case '{':
                    data.push(s[i]);
                    break;

                case ')':
                    if((data.size() > 0) && data.top() == '(')
                    {
                        data.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                
                case '}':
                    if((data.size() > 0) && (data.top() == '{'))
                    {
                        data.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                
                case ']':
                    if((data.size() > 0) && (data.top() == '['))
                    {
                        data.pop();
                    }
                    else
                    {
                        return false;
                    }
                    break;
                
                default:
                break;
                    
            }
        }
        if(data.size() > 0)
        {
            result = false;
        }
        return result;
        
    }
};