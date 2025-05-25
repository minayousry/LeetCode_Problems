
struct CircularQueue
{
    vector<int> data;
    int head;
    int tail;
    int count = 0;

    CircularQueue(int capacity):data(capacity,0)
    {
        head = 0;
        tail = -1;
    }


};

class MyCircularQueue {
public:

    unique_ptr<CircularQueue> buffer;

    MyCircularQueue(int k) {

        buffer = make_unique<CircularQueue>(k);
    }
    
    bool enQueue(int value) {
        
        if(buffer->count < buffer->data.size())
        {
            buffer->tail  = (buffer->tail  + 1) % buffer->data.size();
            buffer->data[buffer->tail] = value;
            buffer->count++;
            return true;
        }
        return false;
         
    }
    
    bool deQueue() {
        if(buffer->count > 0)
        {
            buffer->head  = (buffer->head  + 1) % buffer->data.size();
            buffer->count--;
            return true;
        }
        return false;

    }
    
    int Front() {
        if(buffer->count == 0)
        {
            return -1;
        }
        else
        {
            return buffer->data[buffer->head];
        }
    }
    
    int Rear() {
        if(buffer->count == 0)
        {
            return -1;
        }
        else
        {
            return buffer->data[buffer->tail];
        }
    }
    
    bool isEmpty() {
        return (buffer->count == 0);
    }
    
    bool isFull() {
        return (buffer->count == buffer->data.size());
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */