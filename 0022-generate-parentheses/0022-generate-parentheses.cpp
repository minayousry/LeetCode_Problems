class Solution {
public:
    
    void backtrack(vector<string> &stack,string data,int open_cnt,int closed_cnt,int n)
    {

        if((closed_cnt == open_cnt) && (open_cnt == n))
        {
            stack.push_back(data);
            return;
        }

        if(open_cnt > closed_cnt)
        {
            backtrack(stack,data + ")",open_cnt,closed_cnt + 1,n);
        }

        if(open_cnt < n)
        {
            backtrack(stack,data + "(",open_cnt + 1,closed_cnt,n);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string data;

        backtrack(result,data,0,0,n);

        return result;



        
    }
};