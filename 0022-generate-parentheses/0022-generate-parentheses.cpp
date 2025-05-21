class Solution {
public:

    void backtrack(vector<string> &result,string data,int open_brackets_cnt,int closed_brackets_cnt,int &n)
    {
        if(open_brackets_cnt == n && closed_brackets_cnt == n)
        {
            result.push_back(data);
            return;
        }

        if(open_brackets_cnt < n)
        {
            backtrack(result,data + "(",open_brackets_cnt + 1,closed_brackets_cnt,n);
        }

        if(closed_brackets_cnt < open_brackets_cnt)
        {
            backtrack(result,data + ")",open_brackets_cnt,closed_brackets_cnt + 1,n);
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;

        string data = "";

        backtrack(result,data,0,0,n); 

        return result;   
    }
};