class Stack {
public:
    queue<int> qa, qb;
    // Push element x onto stack.
    void push(int x) {
        qa.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int n = qa.size();
        for (int i = 0; i < n - 1; i++) {
            qa.push(qa.front());
            qa.pop();
        }
        qa.pop();
    }

    // Get the top element.
    int top() {
        int n = qa.size();
        for (int i = 0; i < n - 1; i++) {
            qa.push(qa.front());
            qa.pop();
        }
        int ret = qa.front();
        qa.push(qa.front());
        qa.pop();
        return ret;
    }

    // Return whether the stack is empty.
    bool empty() {
        return (qa.empty() && qb.empty());
    }
};
