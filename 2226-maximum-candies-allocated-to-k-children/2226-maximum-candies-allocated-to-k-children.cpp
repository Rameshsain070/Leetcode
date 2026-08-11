class Solution {
public:
    bool canAllocate(vector<int>& candies, long long k, int mid) {
        long long count = 0;
        for (int c : candies) {
            count += c / mid;
            if (count >= k) return true;
        }
        return false;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        long long total_candies = accumulate(candies.begin(), candies.end(), 0LL);
        if (total_candies < k) return 0;

        int left = 1, right = *max_element(candies.begin(), candies.end()), res = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAllocate(candies, k, mid)) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return res;
    }
};