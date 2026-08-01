class Solution {
public:
    int f(vector<int>& v, int i, int j) {
        if (i == j) return v[i];
        
        int l = v[i] - f(v, i + 1, j);
        int r = v[j] - f(v, i, j - 1);
        
        return max(l, r);
    }
    
    bool predictTheWinner(vector<int>& nums) {
        return f(nums, 0, nums.size() - 1) >= 0;
    }
};