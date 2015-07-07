class Queue {
public:
    stack<int> sa, sb;
    // Push element x to the back of queue.
    void push(int x) {
        sa.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (sb.empty()) {
            while (!sa.empty()) {
                sb.push(sa.top());
                sa.pop();
            }
        }
        sb.pop();
    }

    // Get the front element.
    int peek(void) {
        if (sb.empty()) {
            while (!sa.empty()) {
                sb.push(sa.top());
                sa.pop();
            }
        }
        return sb.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (sa.empty() && sb.empty());
    }
};
