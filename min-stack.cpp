class MinStack {
public:
    stack<int> st;
    stack<int> st_min;
    void push(int x) {
        st.push(x);
        if(st_min.empty() || x <= st_min.top())
            st_min.push(x);
    }

    void pop() {
        if(st.top() <= st_min.top())
            st_min.pop();
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return st_min.top();
    }
};
