class Solution {
public:
    long long sumAndMultiply(int n) {
        string x;
        long long sum = 0;
        while(n > 0){
            int digit = 0;
            digit = n % 10;
            n = n / 10;
            if(digit != 0){
                sum += digit;
                x.push_back(digit + '0');
                digit = 0;
            }
            else{
                digit = 0;
            }
        }
        reverse(x.begin(), x.end());
        if (x.empty()) return 0;
        long long rame = stoi(x);
        long long ans = sum * rame;
        return ans;
    }
};