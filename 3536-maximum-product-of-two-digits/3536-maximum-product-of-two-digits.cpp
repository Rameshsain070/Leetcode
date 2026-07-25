class Solution {
public:
    int maxProduct(int n) {
        long long max1 = 0;
        long long max2 = 0;
        while(n > 0){
            int digit = n % 10;
            if(max1 < digit){
                max2 = max1;
                max1 = digit;
            }
            else if(digit > max2){
                max2 = digit;
            }

            n = n / 10;
            
        }

        return max1 * max2;
    }
};