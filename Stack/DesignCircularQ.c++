class MyCircularQueue {
public:
    int front,rear,size;
    vector<int> q;
    MyCircularQueue(int k) 
    { 
        q.resize(k);
        size=k;
        front=-1;
        rear=-1;
    }
    
    bool enQueue(int value) 
    {
        if(isFull())
        {
           return false; 
        }
        if(rear==-1)front=0;
        rear=(rear+1)%size;
        q[rear]=value;
        return true;
    }
    
    bool deQueue() 
    {
        if(isEmpty())
        {
           return false; 
        }
        if(rear==front)
        {
            front=rear=-1;
            return true;
        }
        front=(front+1)%size;
        return true;
    }
    
    int Front() 
    {
        if(front==-1)return -1;
        return q[front];
    }
    
    int Rear() {
        if(rear==-1)return -1;
        return q[rear];
    }
    
    bool isEmpty() {
       if(front==-1)return true;
       return false;
    }
    
    bool isFull() {
        if((rear + 1) % size == front) return true;
        return false;
    }
};
