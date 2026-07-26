class MinStack {
stack<int> stk;
stack<int> minstk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if (minstk.size() == 0 || val <= minstk.top()) minstk.push(val);
    }
    
    void pop() {
        if (stk.top() == minstk.top()) minstk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
    }
};
