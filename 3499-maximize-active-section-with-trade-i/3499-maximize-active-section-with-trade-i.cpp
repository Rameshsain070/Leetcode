class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int cnt1 = 0;
        for (char c : s) {
            if (c == '1') cnt1++;
        }
        
        int mx = 0;
        int pz = 0;
        bool has1 = false;
        
        int n = s.length();
        int i = 0;
        
        while (i < n) {
            if (s[i] == '0') {
                int cz = 0;
                while (i < n && s[i] == '0') {
                    cz++;
                    i++;
                }
                
                if (has1 && pz > 0) {
                    mx = max(mx, pz + cz);
                }
                
                pz = cz;
                has1 = false;
            } else {
                while (i < n && s[i] == '1') {
                    i++;
                }
                has1 = true;
            }
        }
        
        return cnt1 + mx;
    }
};