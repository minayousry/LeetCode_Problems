class TimeMap {
public:
    unordered_map<string, pair<vector<int>,vector<string>>> dict;


    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        dict[key].first.push_back(timestamp);
        dict[key].second.push_back(value);
    }
    
    string get(string key, int timestamp) {
        string val = "";

        auto it = dict.find(key);

        if(it != dict.end())
        {
            int start = 0;
            int end = dict[key].first.size() - 1;

            int mid;
            while(start <= end)
            {
                mid = start + (end - start)/2;

                int mid_val = dict[key].first[mid];

                if(mid_val <= timestamp)
                {
                    val = dict[key].second[mid];
                    start = mid + 1;
                }
                else if(mid_val > timestamp)
                {
                    end = mid - 1;
                }
            }
        }
        return val;

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */