class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int unknownLeft = 0, unknownRight = 0;
        int sumLeft = 0, sumRight = 0;


        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                unknownLeft++;
            } else {
                sumLeft += num[i] - '0';
            }
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') {
                unknownRight++;
            } else {
                sumRight += num[i] - '0';
            }
        }

   
        if ((unknownLeft + unknownRight) % 2 == 1)
            return true;

        if (unknownLeft > unknownRight) {
            return sumLeft - sumRight
                + 9 * (unknownLeft - unknownRight) / 2 != 0;
        }

        return sumLeft - sumRight
            - 9 * (unknownRight - unknownLeft) / 2 != 0;
    }
};