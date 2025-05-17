class KthLargest {
public:
    multiset<int> data;
    int limit;

    KthLargest(int k, vector<int>& nums) {
        limit = k;
        for(const auto &num:nums)
        {
            data.insert(num);
        }    
    }
    
    int add(int val) {
        
        int result = -1;
        data.insert(val);
        int count = 1;

        for(auto it = data.rbegin();it != data.rend();++it)
        {
            if(count == limit)
            {
                result = *it;
                break;
            }
            count++;
        }

        return result;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */