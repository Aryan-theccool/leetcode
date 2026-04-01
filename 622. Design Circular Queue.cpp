// class MyCircularQueue {
// public:
// queue<int>q;
// int size;
// int cap;
//     MyCircularQueue(int k) {
//       cap=k;
// size=0;  
//  queue<int>q(k);

//     }
    
//     bool enQueue(int value) {
//         if(q.isFull()) return false;
//         int tail=(head+size)%cap;
//         size++;
//         return true;
//     }
    
//     bool deQueue() {
//       if(isEmpty()) return false;
//       head=(head+1)%cap;
// size--;
// return true;
//     }
    
//     int Front() {
//       return isEmpty() ? -1 : data[head];  
//     }
    
//     int Rear() {
        
//     }
    
//     bool isEmpty() {
        
//     }
    
//     bool isFull() {
        
//     }
// };

// /**
//  * Your MyCircularQueue object will be instantiated and called as such:
//  * MyCircularQueue* obj = new MyCircularQueue(k);
//  * bool param_1 = obj->enQueue(value);
//  * bool param_2 = obj->deQueue();
//  * int param_3 = obj->Front();
//  * int param_4 = obj->Rear();
//  * bool param_5 = obj->isEmpty();
//  * bool param_6 = obj->isFull();
//  */
class MyCircularQueue {
public:
    vector<int> data;
    int head;
    int size;
    int cap;

    MyCircularQueue(int k) {
        cap = k;
        size = 0;
        head = 0;
        data.resize(k);
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;

        int tail = (head + size) % cap;
        data[tail] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        head = (head + 1) % cap;
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : data[head];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        int tail = (head + size - 1) % cap;
        return data[tail];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == cap;
    }
};