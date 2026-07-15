class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long even = n * n;
        long long odd = n * n + n;

        long long ans = gcd(even, odd);

        return ans;
    }
};