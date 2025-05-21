class MinStack {
public:
    stack<pair<int,int>> data;

    MinStack() {
        
    }
    
    void push(int val) {
        if(data.empty())
        {
            data.push(make_pair(val,val));
        }
        else
        {
            data.push(make_pair(val,min(val,data.top().second)));
        }
        
    }
    
    void pop() {
        data.pop();
    }
    
    int top() {
        return data.top().first;
    }
    
    int getMin() {
        return data.top().second;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */