class Solution {
public:
    bool isValid(string s) {
        bool result = true;
        stack<char> brackets;

        for(int i=0;i<s.size();++i)
        {
            switch(s[i])
            {
                case '(':
                case '{':
                case '[':
                    brackets.push(s[i]);
                break;

                case ')':
                    if(!brackets.empty() && brackets.top() == '(')
                    {
                        brackets.pop();
                    }
                    else
                    {
                        return false;
                    }
                break;

                case '}':
                    if(!brackets.empty() && brackets.top() == '{')
                    {
                        brackets.pop();
                    }
                    else
                    {
                        return false;
                    }
                break;

                case ']':
                    if(!brackets.empty() && brackets.top() == '[')
                    {
                        brackets.pop();
                    }
                    else
                    {
                        return false;
                    }
                break;
            }

            
            
        }
        if(brackets.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};