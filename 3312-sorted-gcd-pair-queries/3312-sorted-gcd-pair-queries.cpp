class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int max_val = 0;
        for (int num : nums) {
            max_val = max(max_val, num);
        }

        vector<long long> count(max_val + 1, 0);
        for (int num : nums) {
            count[num]++;
        }
        vector<long long> exact_gcd(max_val + 1, 0);

        for (int i = 1; i <= max_val; ++i) {
            long long c = 0;
            for (int j = i; j <= max_val; j += i) {
                c += count[j];
            }
            exact_gcd[i] = c * (c - 1) / 2;
        }
        
        for (int i = max_val; i >= 1; --i) {
            for (int j = 2 * i; j <= max_val; j += i) {
                exact_gcd[i] -= exact_gcd[j];
            }
        }
    
        vector<long long> prefix(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            prefix[i] = prefix[i - 1] + exact_gcd[i];
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        for (long long q : queries) {
            auto it = upper_bound(prefix.begin(), prefix.end(), q);
            ans.push_back(distance(prefix.begin(), it));
        }
        
        return ans;
    }
};