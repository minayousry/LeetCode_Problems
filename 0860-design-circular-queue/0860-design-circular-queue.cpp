
struct circular_queue
{
    int data[1000];
    int head;
    int tail;
    int size;
    int count;
};

class MyCircularQueue {
public:
    struct circular_queue cqueue;
    MyCircularQueue(int k) {
        cqueue.head = 0;
        cqueue.tail = 0;
        cqueue.count = 0;
        cqueue.size = k;
    }   
    
    bool enQueue(int value) {
        if(isFull())
            return false;

        cqueue.data[cqueue.tail % cqueue.size] = value;
        cqueue.tail = (cqueue.tail % cqueue.size) + 1;
        cqueue.count++;
        
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;

        cqueue.head = (cqueue.head % cqueue.size) + 1;
        cqueue.count--;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;

        return cqueue.data[cqueue.head % cqueue.size];
        
    }
    
    int Rear() {
        if(isEmpty())
            return -1;

        return cqueue.data[cqueue.tail - 1 % cqueue.size];
    }
    
    bool isEmpty() {
        if(cqueue.count == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool isFull() {
        if(cqueue.count == cqueue.size)
        {
            return true;
        }
        else
        {
            return false;
        }
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