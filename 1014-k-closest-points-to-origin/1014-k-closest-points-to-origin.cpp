
struct Compare
{
    bool operator()(const pair<double,vector<int>> a,const pair<double, vector<int>> b)
    {
        return a.first > b.first;
    }
};

class Solution {
public:



    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> result;

        priority_queue< pair<double, vector<int>>,vector<pair<double, vector<int>>>,Compare>  points_data;

        for(int i=0;i<points.size();++i)
        {
            
            double calc = sqrt(pow(points[i][0],2) + pow(points[i][1],2));
            points_data.push( {calc, {points[i][0],points[i][1]} } );
            
        }

        while(!points_data.empty() && k > 0)
        {
            auto elm = points_data.top();
            points_data.pop();
            result.push_back(elm.second);
            k--;
        }

        return result;

    }
};