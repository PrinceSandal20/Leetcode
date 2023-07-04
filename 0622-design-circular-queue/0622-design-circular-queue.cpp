class MyCircularQueue {
public:
    vector<int>arr;
    int front,rear,size,capacity;
    MyCircularQueue(int k) {
        arr.resize(k,-1);
        front=0;
        rear=k-1;
        size=0;
        capacity=k;
    }
    
    bool enQueue(int value) {
        if(isFull())return false;
        rear=(rear+1)%capacity;
        arr[rear]=value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())return false;
        arr[front]=-1;
        front=(front+1)%capacity;
        size--;
        return true;
    }
    
    int Front() {
        return arr[front];
    }
    
    int Rear() {
        return arr[rear];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
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