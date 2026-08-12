class Solution {
    int comp(int a, int b, char op) {
        if(op == '+') return a + b;
        else if(op == '-') return a - b;
        else return a * b;
    }
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> ans;
        int n = exp.size(), ok = 1;
        for(int i=0; i<n; i++) {
            if(exp[i] < '0' || exp[i] > '9') {
                ok = 0;
                vector<int> left = diffWaysToCompute(exp.substr(0, i));
                vector<int> right = diffWaysToCompute(exp.substr(i+1, n));

                for(auto &j : left) {
                    for(auto &k : right) {
                        ans.push_back(comp(j, k, exp[i]));
                    }
                }
            }
        }
        if(ok) ans.push_back(stoi(exp));
        return ans;
    }
};