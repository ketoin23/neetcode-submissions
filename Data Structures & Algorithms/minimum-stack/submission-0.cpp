class MinStack {
    stack<int> st, mnSt;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if(mnSt.size()) {
            if(mnSt.top() >= val)
                mnSt.push(val);
        } else {
            mnSt.push(val);
        }
    }
    
    void pop() {
        int cur = st.top();
        st.pop();

        if(mnSt.size()) {
            if(mnSt.top() == cur)
                mnSt.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mnSt.top();
    }
};
