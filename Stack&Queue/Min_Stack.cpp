class MinStack {
public:
    stack<pair<int, int>> st;
    int mn = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        mn = min(mn, val);
        st.push({val, mn});
    }
    
    void pop() {
        st.pop();
        if(st.empty()){
            mn = INT_MAX;
        }
        else mn = st.top().second;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */