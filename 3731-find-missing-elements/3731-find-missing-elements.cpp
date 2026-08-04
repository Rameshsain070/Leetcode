class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int first = nums[0];
        int last = nums[n-1];
        vector<int> rame;
        int i = 0;
        int j = n -1;
        while(last > first || i < j){
            if(nums[i] == first){
                i++;
                first++;
            }
            else{
                rame.push_back(first);
                first++;
            }
        }
        return rame;
    }
};