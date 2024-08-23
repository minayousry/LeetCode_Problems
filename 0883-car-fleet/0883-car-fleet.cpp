class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,int>> cars_info;
        stack<double> time_to_dist;

        for(int i=0;i<position.size();++i)
        {
            cars_info.push_back({position[i],speed[i]});
        }

        sort(cars_info.begin(),cars_info.end());

        double time;

        
        for(int i=cars_info.size() - 1;i>=0;--i)
        {
            time = static_cast<double>(target - cars_info[i].first)/cars_info[i].second;

            if(time_to_dist.empty() || (time > time_to_dist.top()))
            {
                time_to_dist.push(time);
            }
            
        }
        return time_to_dist.size();
        
    }
};