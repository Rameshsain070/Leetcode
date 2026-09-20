class Solution {
public:
    int reverseDegree(string s) {
        vector<int> ram(26, 0);
        int totalDegree = 0;
        int position = 1; 

        for (char ch : s) {
            int index = ch - 'a';
            int revAlphabet = 26 - index; 
            totalDegree += revAlphabet * position;
            position++;
        }
        
        return totalDegree;
    }
};