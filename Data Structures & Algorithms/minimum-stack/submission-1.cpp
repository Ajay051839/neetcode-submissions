class MinStack {
public:
   stack<int>min_st;
   stack<int>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(min_st.empty() || val<=min_st.top()){
            min_st.push(val);
        }
        st.push(val);
    }
    
    void pop() {
        if(!min_st.empty() &&st.top()==min_st.top()){
            min_st.pop();
        }
        st.pop();
    }
    
    int top() {
       return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
