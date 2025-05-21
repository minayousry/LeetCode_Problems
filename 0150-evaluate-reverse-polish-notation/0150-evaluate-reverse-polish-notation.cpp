class Solution {
public:

    
    int evalRPN(vector<string>& tokens) {
        stack<int> data;
        int first_num;
        int second_num;

        for(int i=0;i<tokens.size();++i)
        {
            
                    
            if(tokens[i] == "+")
            {
                first_num = data.top();
                data.pop();
                second_num = data.top();
                data.pop();
                data.push(first_num + second_num);
            }
            else if(tokens[i] == "-")
            {
                first_num = data.top();
                data.pop();
                second_num = data.top();
                data.pop();
                data.push(second_num - first_num);
            }
            else if(tokens[i] == "*")
            {
                first_num = data.top();
                data.pop();
                second_num = data.top();
                data.pop();
                data.push(first_num * second_num);
            }
            else if(tokens[i] == "/")
            {
                first_num = data.top();
                data.pop();
                second_num = data.top();
                data.pop();
                data.push(second_num / first_num);
            }
            else
            {
                data.push(std::stoi(tokens[i]));
            }
        }
        return data.top();

    }

    

};