class MinStack {
public:
    stack<int> ss, ms;
    void push(int x) {
        ss.push(x);
        if (!ms.empty())
            ms.push(min(x, ms.top()));
        else
            ms.push(x);
    }

    void pop() {
        if(!ss.empty()) {
            ss.pop();
            ms.pop();
        }
    }

    int top() {
        if (!ss.empty())
            return ss.top();
    }

    int getMin() {
        if (!ms.empty())
            return ms.top();
    }
};
