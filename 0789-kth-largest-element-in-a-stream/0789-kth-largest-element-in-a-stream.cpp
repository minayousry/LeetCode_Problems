class KthLargest {
public:
    priority_queue<int,vector<int>,std::greater<int>> data;
    int limit;

    KthLargest(int k, vector<int>& nums) {
        limit = k;
        for(const auto &num:nums)
        {
            data.push(num);
        } 

        int pop_limit = data.size() - limit;
        int count = 0;   

        while(!data.empty() && (count < pop_limit))
        {
            data.pop();
            count++;
        }
    }
    
    int add(int val) {
        data.push(val);
        
        if (data.size() > limit) {
            data.pop();
        }
        return data.top();

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */