class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int ans = 0;
    
        arr[0] = 1;
        ans = max(arr[0], ans);

        for(int i = 1; i < n; i++){
            if(abs(arr[i] - arr[i-1]) <= 1){
                ans = max(arr[i],ans);
            }
            if(abs(arr[i] - arr[i-1]) > 1){
                arr[i] = arr[i-1] + 1;
                ans = max(arr[i],ans);
            }
            
        }

        return ans;
    }
};