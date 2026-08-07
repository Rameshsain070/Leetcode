class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_set<string> operators = {"*", "-", "+", "/"};

        for (string s : tokens) {
            if (operators.find(s) != operators.end()) {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                int res = 0;
                if (s == "/") res = a / b;
                else if (s == "*") res = a * b;
                else if (s == "-") res = a - b;
                else if (s == "+") res = a + b;

                st.push(res);
            } else {
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};