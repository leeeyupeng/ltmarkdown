#include"leetcode.h"

class MyQueue {
public:
    stack<int> front;
    stack<int> back;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        back.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int pop = peek();
        front.pop();
        return pop;
    }
    
    /** Get the front element. */
    int peek() {
        int pop;
        if(!front.empty()){
        }
        else{
            while(!back.empty()){
                front.push(back.top());
                back.pop();
            }
        }
        pop = front.top();
        return pop;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return front.empty() && back.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */