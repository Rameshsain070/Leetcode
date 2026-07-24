class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> u(nums.begin(), nums.end());
        unordered_set<int> c = {0};
        
        for (int i = 0; i < 3; ++i) {
            unordered_set<int> n;
            for (int v : c) {
                for (int x : u) {
                    n.insert(v ^ x);
                }
            }
            c = move(n);
        }
        
        return c.size();
    }
};