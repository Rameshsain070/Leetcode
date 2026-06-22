class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.length();
        int bb = 0;
        for(int i = 0; i < n; i++){
            if(text[i] == 'b'){
                bb++;
            }
        }
        int aa = 0;
        for(int i = 0; i < n; i++){
            if(text[i] == 'a'){
                aa++;
            }
        }
        int le = 0;
        for(int i = 0; i < n; i++){
            if(text[i] == 'l'){
                le++;
            }
        }
        int oe = 0;
        for(int i = 0; i < n; i++){
            if(text[i] == 'o'){
                oe++;
            }
        }
        int nn = 0;
        for(int i = 0; i < n; i++){
            if(text[i] == 'n'){
                nn++;
            }
        }


        return min({bb, aa, nn, le / 2, oe / 2});

    }
};