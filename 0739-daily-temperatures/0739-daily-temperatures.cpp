class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> result(temperatures.size(),0);
        stack<pair<int,int>> temp;
        for(int i=0;i<temperatures.size();++i)
        {
            while(!temp.empty() && (temperatures[i] > temp.top().first))
            {
                pair<int,int> last_record = temp.top();
                temp.pop();
                result[last_record.second] = i - last_record.second;
            }
            temp.push({temperatures[i],i});
        }
        return result;
        
    }
};