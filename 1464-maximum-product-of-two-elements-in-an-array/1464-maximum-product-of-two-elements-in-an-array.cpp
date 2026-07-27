class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int first = nums[n - 1];
        int second = nums[n - 2];

        return (first - 1) * (second - 1);
    }
};