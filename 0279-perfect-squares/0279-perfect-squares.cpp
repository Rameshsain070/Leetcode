class Solution {
public:
    vector<int> dp;

    int helper(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        if (dp[n] != -1) return dp[n];

        int res = INT_MAX;

        for (int i = 1; i * i <= n; i++) {
            int x = min(res, 1 + helper(n - i * i));
            res = min(res, x);
        }

        return dp[n] = res;
    }

    int numSquares(int n) {
        dp.assign(n + 1, -1);
        return helper(n);
    }
};