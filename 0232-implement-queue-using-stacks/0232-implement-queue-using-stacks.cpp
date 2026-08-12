class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    void push(int x) {
        s2.push(x);
        stack<int> s;
        while (!s1.empty()) {
            s.push(s1.top());
            s1.pop();
        }
        while (!s.empty()) {
            s2.push(s.top());
            s.pop();
        }
        swap(s1, s2);
        return;
    }
    int pop() {
        int x = s1.top();
        s1.pop();
        return x;
    }

    int peek() { return s1.top(); }

    bool empty() { return (s1.size() == 0); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */