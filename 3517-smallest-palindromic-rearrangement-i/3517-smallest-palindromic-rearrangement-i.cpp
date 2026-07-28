class Solution {
public:
    string smallestPalindrome(string s) {
        int f[26] = {0}; 
        for (int i = 0; i < s.length(); i++) {
            f[s[i] - 'a']++;
        }
        
        string l = "";
        string m = "";
        
        for (int i = 0; i < 26; i++) {
            if (f[i] > 0) {
                l += string(f[i] / 2, i + 'a');
                
                if (f[i] % 2 != 0) {
                    m += (char)(i + 'a');
                }
            }
        }
        
        string r = l;
        reverse(r.begin(), r.end());
        
        return l + m + r;
    }
};