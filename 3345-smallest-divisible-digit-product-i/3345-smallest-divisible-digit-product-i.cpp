class Solution {
private:
    int getDigitProduct(int num) {
        int pr = 1;
        while (num > 0) {
            pr *= (num % 10);
            num /= 10;
        }
        return pr;
    }

public:
    int smallestNumber(int n, int t) {
        while (true) {
            if (getDigitProduct(n) % t == 0) {
                return n;
            }
            n++;
        }
    }
};