class MyCircularDeque {
public:
    vector<int> v;
    int size = 0;
    int front = 0;  
    int back = 0;
    int capacity = 0;

    MyCircularDeque(int k) {
        v = vector<int>(k, -1);
        capacity = k;
        front = 0;
        back = k - 1;  
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;  
        v[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        back = (back + 1) % capacity; 
        v[back] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        v[front] = -1;  
        front = (front + 1) % capacity;  
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        v[back] = -1;  
        back = (back - 1 + capacity) % capacity;  
        size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return v[front];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return v[back];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};
