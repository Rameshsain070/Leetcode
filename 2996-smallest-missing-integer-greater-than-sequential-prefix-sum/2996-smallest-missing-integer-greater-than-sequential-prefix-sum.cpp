class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int i = 1;
        while(i < nums.size()){
            if(nums[i-1] + 1 == nums[i]){
                sum += nums[i];
                i++;
            }
            else{
                break;
            }
        }
        int j = 0;
        while(j < nums.size()){
            if(nums[j] == sum){
                sum = sum + 1;
                j = 0;
            }
            j++;
            
        }
        return sum;
    }
};