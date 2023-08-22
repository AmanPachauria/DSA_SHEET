class MyQueue {
public:
    stack<int> st1, st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
       if(st2.size()!=0){
           int temp = st2.top();
           st2.pop();
           return temp;
       }
       else{
           while(st1.size()!=0){
               st2.push(st1.top());
               st1.pop();
           }
           return pop();
       }
    }
    
    int peek() {
       if(st2.size()!=0){
           int temp = st2.top();
           return temp;
       }
       else{
           while(st1.size()!=0){
               st2.push(st1.top());
               st1.pop();
           }
           return peek();
       }
    }
    
    bool empty() {
        return (st1.empty() && st2.empty());
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