class Solution {
public:
    int f(vector<int>& p, int i, int j, vector<vector<int>>& m) {
        if (i > j) return 0;
        if (m[i][j] != -1) return m[i][j];
        
        int l = p[i] - f(p, i + 1, j, m);
        int r = p[j] - f(p, i, j - 1, m);
        
        return m[i][j] = max(l, r);
    }
    
    bool stoneGame(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> m(n, vector<int>(n, -1));
        return f(p, 0, n - 1, m) > 0;
    }
};