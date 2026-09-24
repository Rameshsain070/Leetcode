class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int mt = -1;
        for(int i = 0; i < n; i++){
            string st = to_string(nums[i]);
            int nt = st.size();
            int tot = 0;
            for(int j = 0; j < nt; j++){
                tot = tot + (st[j] - '0');
            }
            if(tot == i){
                mt = i;
                break;
            }
        }
        return mt;
    }
};