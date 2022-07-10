class MinStack {
public:
    stack<int> data;
    stack<int> min_val;
    
    MinStack() 
    {
        
    }
    
    void push(int val)
    {
        data.push(val);
        if(min_val.empty())
        {
            min_val.push(val);
        }
        else if(val < min_val.top())
        {
            min_val.push(val);
        }
        else
        {
            min_val.push(min_val.top());
        }

    }
    
    void pop() 
    {
        min_val.pop();
        data.pop();

    }
    
    int top()
    {
        return data.top();    
    }
    
    int getMin() 
    {
        return min_val.top();    
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