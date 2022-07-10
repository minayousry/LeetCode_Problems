#include <iterator>

class KthLargest {
public:
    int largest_k;
    priority_queue <int, vector<int>, greater<int> > data;
    KthLargest(int k, vector<int>& nums)
    {
        largest_k = k;
        int count = 0;
        for(auto num:nums)
        {
            data.push(num);
            count++;
        }
        
        while(count > k)
        {
            data.pop();
            count--;
        }
        

        
    }
    
    int add(int val)
    {
        int result = 0;
        data.push(val);
        
        if(data.size() > largest_k)
            data.pop();
        
        result = data.top();
        
        return result;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */