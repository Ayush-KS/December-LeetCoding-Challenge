// Largest Rectangle in Histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> st;
        
        for(int i = 0; i <= n; i++) {
            int h = i == n ? 0 : heights[i];
            if(st.empty() || (h >= heights[st.top()])) {
                st.push(i);
            } else {
                int hz = heights[st.top()];
                st.pop();
                ans = max(ans, hz * (st.empty() ? i : i - st.top() - 1));
                i--;
            }
        }
        return ans;
    }
};