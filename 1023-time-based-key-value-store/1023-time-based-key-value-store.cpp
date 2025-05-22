class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> dict;


    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        dict[key].push_back({timestamp,value});
        
    }
    
    string get(string key, int timestamp) {
        string val = "";

        auto it = dict.find(key);

        if(it != dict.end())
        {
            int start = 0;
            int end = dict[key].size() - 1;

            int mid;
            int mid_val;
            while(start <= end)
            {
                mid = start + (end - start)/2;

                mid_val = dict[key][mid].first;

                if(mid_val <= timestamp)
                {
                    val = dict[key][mid].second;
                    start = mid + 1;
                }
                else
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