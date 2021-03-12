#include"leetcode.h"

class CQueue {
private:
    stack<int> head;
    stack<int> tail;
    int top;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        tail.push(value);
    }
    
    int deleteHead() {
        if(head.empty()){
            while(!tail.empty()){
                head.push(tail.top());
                tail.pop();
            }
        }
        if(head.empty()){return -1;}
        top = head.top();
        head.pop();
        return top;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */