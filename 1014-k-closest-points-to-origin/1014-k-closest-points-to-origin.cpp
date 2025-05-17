struct Compare
{
    bool operator()(const pair<double,vector<int>>& a,const pair<double,vector<int>>& b)
    {
        return (a.first > b.first);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> result;
        priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>,Compare> points_data;

        double distance;

        for(const auto &point:points)
        {
            distance = sqrt(pow(point[0],2) + pow(point[1],2));
            points_data.push(make_pair(distance,point));
        }

        int count = 0;

        while(!points.empty() && count < k)
        {
            result.push_back(points_data.top().second);
            points_data.pop();
            count++;
        }

        return result;
    }
};