class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> map('z' + 1, "");
        unordered_map<string, int> map2;
        int left = 0;
        int left2 = 0;
        while (left < s.length()) {
            string temp;
            while (left < s.length() && s[left] != ' ') {
                temp.push_back(s[left]);
                left++;
            }
            left++;
            if (map[pattern[left2]] == "" && map2[temp] == 0) {
                map[pattern[left2]] = temp;
                map2[temp] = pattern[left2];
            } else if (map[pattern[left2]] != temp ||
                       map2[temp] != pattern[left2]) {
                return false;
            }
            left2++;
        }
        if (left2 != pattern.length()) {
            return false;
        }
        return true;
    }
};