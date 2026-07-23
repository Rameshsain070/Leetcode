class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        
        int rame = 1;
        
        while (rame <= n) {
            rame = rame * 2;
        }
        
        return rame;
    }
};