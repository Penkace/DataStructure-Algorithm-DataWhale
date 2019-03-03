class MyCircularDeque {
private:
    vector<int> qu;
    int size;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(qu.size()>=size) return false;
        qu.insert(qu.begin(),value);
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(qu.size()>=size) return false;
        qu.push_back(value);
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(qu.size()==0) return false;
        qu.erase(qu.begin());
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(qu.size()==0) return false;
        qu.pop_back();
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(qu.size()==0) return -1;
        return qu[0];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(qu.size()==0) return -1;
        return qu[qu.size()-1];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return qu.size()==0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return qu.size()==size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.insertFront(value);
 * bool param_2 = obj.insertLast(value);
 * bool param_3 = obj.deleteFront();
 * bool param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * bool param_7 = obj.isEmpty();
 * bool param_8 = obj.isFull();
 */
