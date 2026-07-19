class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26, 0);
        for(int i = 0; i < s.length(); i++){
            lastIndex[s[i] - 'a'] = i; 
        }
        
        vector<bool> seen(26, false); 
        
        string st = ""; 
        
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            
            if(seen[ch - 'a']) {
                continue;
            }
            
            while(!st.empty() && ch < st.back() && lastIndex[st.back() - 'a'] > i) {
                seen[st.back() - 'a'] = false;
                st.pop_back();
            }
            st.push_back(ch);
            seen[ch - 'a'] = true;
        }
        
        return st;
    }
};