class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<pair<int,int>> rec_info;
        int max_area = 0;
        int width = 0;
        int height = 0;
        int start;

        for(int i=0;i<heights.size();++i)
        {
            start = i;
            while(!rec_info.empty() && heights[i] < rec_info.top().second)
            {
                height = rec_info.top().second;
                width = i - rec_info.top().first;
                max_area = max(max_area,width*height);
                start = rec_info.top().first;
                rec_info.pop();

            }

            rec_info.push({start,heights[i]});

        }

        while(!rec_info.empty())
        {
            height = rec_info.top().second;
            width = heights.size() - rec_info.top().first;
            max_area = max(max_area,width*height);
            rec_info.pop();
        }
        return max_area;
    }
};