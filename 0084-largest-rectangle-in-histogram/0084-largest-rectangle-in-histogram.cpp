class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxi=0;
        stack<int>st;
        for(int i=0;i<=n;i++){ 
             while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int ht = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;
                maxi = max(maxi, ht * width);
            }
            st.push(i);
        }
        return maxi;
    }
};