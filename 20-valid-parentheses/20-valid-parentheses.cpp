class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> data;
        bool state = true;
        
        if((s.size() == 1) || (s.size() %2 == 1))
        {
            return false;
        }
        else
        {
            //data.push(s[0]);
            
            
            int counter1 = 0;
            int counter2 = 0;
            int counter3 = 0;
            
            for(int i = 0;i<s.size();++i)
            {
                switch(s[i])
                {
                    case '}':
                        if(data.size() > 0 && (data.top() == '{'))
                        {
                            data.pop();
                            counter1--;
                        }
                        else
                        {
                            counter1 = -1;
                        }

                        break;
                        
                    case ']':
                        if(data.size() > 0 && data.top() == '[')
                        {
                            data.pop();
                            counter2--;
                        }
                        else
                        {
                            counter2 = -1;
                        }

                        break;
                        
                   case ')':
                        if(data.size() > 0 && data.top() == '(')
                        {
                            data.pop();
                            counter3--;
                        }
                        else
                        {
                            counter3 = -1;
                        }

                        break;
                        
                    case '{':
                        data.push(s[i]);
                        counter1+=1;
                        break;
                    case '[':
                        data.push(s[i]);
                        counter2+=1;
                        break;
                    case '(':
                        data.push(s[i]);
                        counter3+=1;
                        break;
                }
                if((counter1 < 0) || (counter2<0) || (counter3<0))
                {
                    state = false;
                    break;
                }
                
            }
            
            if( (counter1+counter2+counter3) != 0)
            {
              state = false;
            }
        }
        
        return state;
        
    }
};